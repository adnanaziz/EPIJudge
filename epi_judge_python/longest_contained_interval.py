from typing import List

from test_framework import generic_test


def longest_contained_range(A: List[int]) -> int:
    # TODO - you fill in here.
    return 0


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('longest_contained_interval.py',
                                       'longest_contained_interval.tsv',
                                       longest_contained_range))
