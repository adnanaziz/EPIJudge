# @library
import enum
import sys


class ConsoleColor:
    FG_RED = '\033[31m'
    FG_GREEN = '\033[32m'
    FG_BLUE = '\033[34m'
    FG_DEFAULT = '\033[39m'


def use_tty_output():
    if not use_tty_output.__dict__.get('cached', None):
        use_tty_output.cached = sys.stdout.isatty()
    return use_tty_output.cached


class TestResult(enum.Enum):
    PASSED = 0
    FAILED = 1
    TIMEOUT = 2
    UNKNOWN_EXCEPTION = 3
    STACK_OVERFLOW = 4

    def __str__(self):
        def colored(text, color):
            if use_tty_output():
                return color + text + ConsoleColor.FG_DEFAULT
            else:
                return text

        if self == TestResult.PASSED:
            return colored('PASSED', ConsoleColor.FG_GREEN)
        if self == TestResult.FAILED:
            return colored('FAILED', ConsoleColor.FG_RED)
        if self == TestResult.TIMEOUT:
            return colored('TIMEOUT', ConsoleColor.FG_BLUE)
        if self == TestResult.UNKNOWN_EXCEPTION:
            return colored('UNHANDLED EXCEPTION', ConsoleColor.FG_RED)
        if self == TestResult.STACK_OVERFLOW:
            return colored('STACK OVERFLOW', ConsoleColor.FG_RED)
        raise RuntimeError('Unknown TestResult')
