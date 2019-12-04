"""
This tool is intended for automated CI testing.
"""
import enum
import os
import re
import subprocess
import sys
from pathlib import Path
from subprocess import TimeoutExpired, CompletedProcess
from typing import List, Optional

import click


class TestMode(enum.Enum):
    STUB = 'stub'
    SOLUTION = 'solution'


class Language(enum.Enum):
    CPP = 'cpp'
    JAVA = 'java'
    PYTHON = 'python'


def strip_ascii_codes(s: str) -> str:
    ansi_escape = re.compile(
        r'''
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


def execute_program(args: List[str], mode: TestMode) -> None:
    """Executes given program and checks its output
    for strings specific for either test failure
    (for testing stub programs) or success
    (for testing solution programs).

    :param args: arguments to be executed
    :param mode: checking mode
    """
    args_str = ' '.join(args)

    def check_output(result: CompletedProcess):
        stdout = strip_ascii_codes(result.stdout.decode())
        error_string = f'Failure:\nMode: {mode.value}\nCommand: {args_str}\nExit code: {result.returncode:X}\nOutput:\n{stdout}\n'
        if mode == TestMode.STUB:
            if result.returncode not in (1, 2) or 'Test FAILED' not in stdout:
                raise RuntimeError(error_string)
        elif mode == TestMode.SOLUTION:
            if (result.returncode != 0 or
                    "*** You've passed ALL tests. Congratulations! ***" not in stdout):
                raise RuntimeError(error_string)
        else:
            print('Invalid mode: {}'.format(mode))
            sys.exit(1)

    try:
        result = subprocess.run(args, stdout=subprocess.PIPE, timeout=300)
        check_output(result)
    except RuntimeError as e:
        print(e)
        sys.exit(1)
    except TimeoutExpired:
        print(f"{mode} > {args_str}: TIMEOUT")
        sys.exit(1)


def get_exec_args(file: Path, lang: Language, test_data_dir: Path) -> List[str]:
    common_args = ['--test-data-dir', str(test_data_dir), '--no-tty']
    if lang == Language.PYTHON:
        return [sys.executable, str(file)] + common_args
    if lang == Language.CPP:
        return [str(file)] + common_args
    if lang == Language.JAVA:
        return [
            'make', '-C',
            str(file.parent.parent),
            file.with_suffix('').name
        ]  # Ad-hoc version
    raise NotImplementedError()


def scan_lang_folder(src_dir: Path, build_dir: Optional[Path],
                     lang: Language, mode: TestMode) -> List[Path]:
    """Search for all stab and solution files in the folder.
    """
    lang_dir = f"epi_judge_{lang.value}"
    if mode == TestMode.SOLUTION:
        lang_dir += '_solutions'
    src_dir = src_dir / lang_dir

    if lang == Language.PYTHON:
        return sorted([f for f in src_dir.glob("*.py")
                       if find_str_in_file(f, 'generic_test_main')])
    elif lang == Language.CPP:
        if not build_dir:
            raise RuntimeError('Missing --build-dir')
        solution_files = (f.with_suffix('').name for f in src_dir.glob("*.cc")
                          if find_str_in_file(f, 'GenericTestMain'))
        EXCLUDED_FILES = ['queue_with_max_using_deque', 'reverse_list']
        solution_files = sorted([build_dir / f for f in solution_files 
                                 if f not in EXCLUDED_FILES])
        if os.name == 'nt':
            return [f.with_suffix('.exe') for f in solution_files]
        else:
            return solution_files
    elif lang == Language.JAVA:
        EXCLUDED_FILES = ['QueueWithMaxUsingDeque.java', 'ReverseList.java']
        return sorted([
            f for f in (src_dir / 'epi').glob("*.java") if
            (find_str_in_file(f, '@EpiTest') and f.name not in EXCLUDED_FILES)
        ])

    raise NotImplementedError()


@click.command(
    'check_judge',
    help='A tool for executing all judge programs in of a given kind.')
@click.option('--build-dir',
              help='Build directory (for C++)',
              type=click.Path(file_okay=False, exists=True))
@click.argument('lang',
                type=click.Choice([Language.CPP.value, Language.JAVA.value, Language.PYTHON.value]))
@click.argument('mode', type=click.Choice([TestMode.STUB.value, TestMode.SOLUTION.value]))
@click.argument('src_dir', type=click.Path(file_okay=False, exists=True))
def check_judge(build_dir: str, src_dir: str, lang: str, mode: str) -> None:
    lang = Language(lang)
    mode = TestMode(mode)
    if build_dir:
        build_dir = Path(build_dir).absolute()
    src_dir = Path(src_dir).absolute()
    test_data_dir = src_dir / 'test_data'

    files = scan_lang_folder(src_dir, build_dir, lang, mode)
    if not files:
        print('Programs are not found')
        exit(1)

    for i, f in enumerate(files):
        print(f"[{i + 1}/{len(files)}] {f}", flush=True)
        args = get_exec_args(f, lang, test_data_dir)
        execute_program(args, mode)
    print('Success')


if __name__ == '__main__':
    check_judge()
