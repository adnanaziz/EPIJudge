from typing import List

from test_framework import generic_test


def count_inversions(A: List[int]) -> int:
    # TODO - you fill in here.
    return 0


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('count_inversions.py',
                                       'count_inversions.tsv',
                                       count_inversions))
