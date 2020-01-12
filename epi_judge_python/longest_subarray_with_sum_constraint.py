from typing import List

from test_framework import generic_test


def find_longest_subarray_less_equal_k(A: List[int], k: int) -> int:
    # TODO - you fill in here.
    return 0


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            'longest_subarray_with_sum_constraint.py',
            'longest_subarray_with_sum_constraint.tsv',
            find_longest_subarray_less_equal_k))
