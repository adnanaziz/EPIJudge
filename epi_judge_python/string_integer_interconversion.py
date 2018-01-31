from test_framework.test_failure_exception import TestFailureException


def int_to_string(x):
    # Implement this placeholder.
    return ''


def string_to_int(s):
    # Implement this placeholder.
    return 0


def wrapper(x, s):
    if int_to_string(x) != s:
        raise TestFailureException("Int to string conversion failed")
    if string_to_int(s) != x:
        raise TestFailureException("String to int conversion failed")


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main(
        'string_integer_interconversion.tsv', wrapper)
