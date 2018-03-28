import collections
from sys import exit

from test_framework import generic_test, test_utils

Subarray = collections.namedtuple('Subarray', ('start', 'end'))


def find_longest_increasing_subarray(A):
    # Implement this placeholder.
    return Subarray(0, 0)


def find_longest_increasing_subarray_wrapper(A):
    result = find_longest_increasing_subarray(A)
    return result.end - result.start + 1


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            'longest_increasing_subarray.tsv',
            find_longest_increasing_subarray_wrapper))
