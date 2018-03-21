from sys import exit

from test_framework import generic_test, test_utils
from test_framework.test_failure import TestFailure


def find_missing_element(stream):
    # Implement this placeholder.
    return 0


def find_missing_element_wrapper(data):
    try:
        return find_missing_element(iter(data))
    except ValueError:
        raise TestFailure('Unexpected no_missing_element exception')


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('absent_value_array.tsv',
                                       find_missing_element_wrapper))
