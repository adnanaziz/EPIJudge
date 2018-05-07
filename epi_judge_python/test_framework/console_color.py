
import sys
from enum import Enum, auto

from test_framework import platform


class ConsoleColor(Enum):
    FG_RED = auto()
    FG_GREEN = auto()
    FG_BLUE = auto()
    FG_YELLOW = auto()
    FG_DEFAULT = auto()


_color_codes_win = {
    ConsoleColor.FG_RED: 4 | 8, ConsoleColor.FG_GREEN: 2 | 8,
    ConsoleColor.FG_BLUE: 1 | 8, ConsoleColor.FG_YELLOW: 6 | 8,
    ConsoleColor.FG_DEFAULT: 7
}


def get_color_code_win(color):
    return _color_codes_win[color]


_color_codes_unix = {
    ConsoleColor.FG_RED: '\033[31m', ConsoleColor.FG_GREEN: '\033[32m',
    ConsoleColor.FG_BLUE: '\033[34m', ConsoleColor.FG_YELLOW: '\033[33m',
    ConsoleColor.FG_DEFAULT: '\033[39m'
}


def get_color_code_unix(color):
    return _color_codes_unix[color]


def print_std_out_colored(color, value):
    if not platform.use_color_output():
        print(value, end='')
        return

    if platform.running_on_win():
        old_text_attr = platform.get_console_screen_buffer_info().wAttributes

        sys.stdout.flush()
        platform.set_console_text_attribute(get_color_code_win(color))

        print(value, end='')

        sys.stdout.flush()
        platform.set_console_text_attribute(old_text_attr)
    else:
        print(
            '{}{}{}'.format(
                get_color_code_unix(color), value,
                get_color_code_unix(ConsoleColor.FG_DEFAULT)),
            end='')
