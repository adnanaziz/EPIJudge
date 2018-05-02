from test_framework import generic_test
from test_framework.test_failure import TestFailure


def int_to_string(x):
    # TODO - you fill in here.
    return ''


def string_to_int(s):
    # TODO - you fill in here.
    return 0


def wrapper(x, s):
    if int_to_string(x) != s:
        raise TestFailure("Int to string conversion failed")
    if string_to_int(s) != x:
        raise TestFailure("String to int conversion failed")


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("string_integer_interconversion.py",
                                       'string_integer_interconversion.tsv',
                                       wrapper))
