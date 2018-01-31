# @library
import sys

from test_framework import platform


class ConsoleColor:
    FG_RED = 0
    FG_GREEN = 1
    FG_BLUE = 2
    FG_DEFAULT = 3


def get_color_code_win(color):
    values = {
        ConsoleColor.FG_RED: 4 | 8, ConsoleColor.FG_GREEN: 2 | 8,
        ConsoleColor.FG_BLUE: 1 | 8, ConsoleColor.FG_DEFAULT: 7
    }
    return values[color]


def get_color_code_unix(color):
    values = {
        ConsoleColor.FG_RED: '\033[31m', ConsoleColor.FG_GREEN: '\033[32m',
        ConsoleColor.FG_BLUE: '\033[34m', ConsoleColor.FG_DEFAULT: '\033[39m'
    }
    return values[color]


def print_std_out_colored(color, value):
    if not platform.use_color_output():
        print(value, end='')
        return

    if platform.running_on_win():
        old_color_attrs = platform.get_console_screen_buffer_info().wAttributes
        sys.stdout.flush()

        platform.set_console_text_attribute(get_color_code_win(color))

        print(value, end='')
        sys.stdout.flush()

        platform.set_console_text_attribute(old_color_attrs)
    else:
        print(
            '{}{}{}'.format(
                get_color_code_unix(color), value,
                get_color_code_unix(ConsoleColor.FG_DEFAULT)),
            end='')
