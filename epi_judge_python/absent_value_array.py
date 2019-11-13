from typing import Iterator

from test_framework import generic_test
from test_framework.test_failure import TestFailure


def find_missing_element(stream: Iterator[int]) -> int:
    # TODO - you fill in here.
    return 0


def find_missing_element_wrapper(stream):
    try:
        res = find_missing_element(iter(stream))
        if res in stream:
            raise TestFailure('{} appears in stream'.format(res))
    except ValueError:
        raise TestFailure('Unexpected no missing element exception')


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('absent_value_array.py',
                                       'absent_value_array.tsv',
                                       find_missing_element_wrapper))
