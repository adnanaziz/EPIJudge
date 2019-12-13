import itertools
from typing import List

from test_framework import generic_test


def find_longest_subarray_less_equal_k(A: List[int], k: int) -> int:

    # Builds the prefix sum according to A.
    prefix_sum = list(itertools.accumulate(A))

    # Early returns if the sum of A is smaller than or equal to k.
    if prefix_sum[-1] <= k:
        return len(A)

    # Builds min_prefix_sum.
    min_prefix_sum = prefix_sum.copy()
    for i in reversed(range(len(min_prefix_sum) - 1)):
        min_prefix_sum[i] = min(min_prefix_sum[i], min_prefix_sum[i + 1])

    a = b = max_length = 0
    while a < len(A) and b < len(A):
        min_curr_sum = (min_prefix_sum[b] -
                        prefix_sum[a - 1] if a > 0 else min_prefix_sum[b])
        if min_curr_sum <= k:
            curr_length = b - a + 1
            if curr_length > max_length:
                max_length = curr_length
            b += 1
        else:  # min_curr_sum > k.
            a += 1
    return max_length


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            'longest_subarray_with_sum_constraint.py',
            'longest_subarray_with_sum_constraint.tsv',
            find_longest_subarray_less_equal_k))
