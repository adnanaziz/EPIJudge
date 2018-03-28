from sys import exit

from test_framework import generic_test, test_utils
from test_framework.test_failure import TestFailure


def int_to_string(x):
    # Implement this placeholder.
    return ''


def string_to_int(s):
    # Implement this placeholder.
    return 0


def wrapper(x, s):
    if int_to_string(x) != s:
        raise TestFailure("Int to string conversion failed")
    if string_to_int(s) != x:
        raise TestFailure("String to int conversion failed")


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('string_integer_interconversion.tsv',
                                       wrapper))
