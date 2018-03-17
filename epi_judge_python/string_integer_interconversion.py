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
    # The timeout is set to 30 seconds.
    # If your program ends with TIMEOUT error probably it stuck in an infinity loop,
    # You can extend the limit by changing the following line.
    timeout_seconds = 30

    exit(
        generic_test.generic_test_main(
            timeout_seconds, 'string_integer_interconversion.tsv', wrapper))
