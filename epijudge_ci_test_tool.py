"""
This tool is intended for automated CI testing.
"""
import enum
import re
import subprocess
import sys
from pathlib import Path
from subprocess import TimeoutExpired, CompletedProcess
from typing import List

import click


class TestMode(enum.Enum):
    STUB = 'stub'
    SOLUTION = 'solution'


class Language(enum.Enum):
    CPP = 'cpp'
    JAVA = 'java'
    PYTHON = 'python'


def strip_ascii_codes(s: str) -> str:
    ansi_escape = re.compile(r'''
        \x1B    # ESC
        [@-_]   # 7-bit C1 Fe
        [0-?]*  # Parameter bytes
        [ -/]*  # Intermediate bytes
        [@-~]   # Final byte
    ''', re.VERBOSE)
    return ansi_escape.sub('', s)


def find_str_in_file(f: Path, s: str) -> bool:
    """Check if the given string is contained in the file.

    :param f: file to search in
    :param s: string to search to
    """
    return f.read_text(encoding='utf-8').find(s) != -1


def resolve_lang_path(dir: str, lang: Language, mode: TestMode) -> Path:
    """Convert run parameters to a language folder.
    """
    lang_dir = f"epi_judge_{lang.value}"
    if mode == TestMode.SOLUTION:
        lang_dir += '_solutions'
    return Path(dir).absolute() / lang_dir


def execute_program(args: List[str], mode: TestMode):
    """Executes given program and checks its output
    for strings specific for either test failure
    (for testing stub programs) or success
    (for testing solution programs).

    :param args: arguments to be executed
    :param mode: checking mode
    """
    args_str = ' '.join(args)

    def check_output(result: CompletedProcess):
        stdout = strip_ascii_codes(result.stdout.decode('utf8'))
        error_string = f'{mode} > {args_str}: rc == {result.returncode}\nOutput:\n{stdout}'
        if mode == TestMode.STUB:
            if result.returncode != 1 or 'Test FAILED' not in stdout:
                raise RuntimeError(error_string)
        else:
            assert mode == TestMode.SOLUTION
            if (result.returncode != 0 or
                    "*** You've passed ALL tests. Congratulations! ***" not in stdout):
                raise RuntimeError(error_string)

    try:
        result = subprocess.run(args, stdout=subprocess.PIPE, timeout=300)
        check_output(result)
    except RuntimeError as e:
        print(e)
        sys.exit(1)
    except TimeoutExpired:
        print(f"{mode} > {args_str}: TIMEOUT")
        sys.exit(1)


def scan_python_folder(folder: Path) -> List[Path]:
    """Search for all stab and solution files in the folder.
    """
    return sorted([f for f in folder.glob("*.py")
                   if find_str_in_file(f, 'generic_test_main')])


@click.command('check_judge', help='A tool for executing all judge programs in of a given kind.')
@click.option('--dir', help='EPIJudge root folder',
              type=click.Path(file_okay=False, exists=True), default='.')
@click.argument('lang',
                type=click.Choice([Language.CPP.value, Language.JAVA.value, Language.PYTHON.value]))
@click.argument('mode', type=click.Choice([TestMode.STUB.value, TestMode.SOLUTION.value]))
def check_judge(dir: str, lang: str, mode: str):
    lang = Language(lang)
    mode = TestMode(mode)
    if lang in (Language.CPP, Language.JAVA):
        raise NotImplementedError()

    lang_dir = resolve_lang_path(dir, lang, mode)
    files = scan_python_folder(lang_dir)
    if not files:
        print('Python programs not found')
        exit(1)

    for i, f in enumerate(files):
        print(f"[{i + 1}/{len(files)}] {f}")
        execute_program([sys.executable, str(f)], mode)
    print('Success')


if __name__ == '__main__':
    check_judge()
