from typing import List

from test_framework import generic_test


def max_subarray_sum_in_circular(A: List[int]) -> int:
    # TODO - you fill in here.
    return 0


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            'maximum_subarray_in_circular_array.py',
            'maximum_subarray_in_circular_array.tsv',
            max_subarray_sum_in_circular))
