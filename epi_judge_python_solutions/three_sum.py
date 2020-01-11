from typing import List

from test_framework import generic_test
from two_sum import has_two_sum


def has_three_sum(A: List[int], t: int) -> bool:

    A.sort()
    # Finds if the sum of two numbers in A equals to t - a.
    return any(has_two_sum(A, t - a) for a in A)


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('three_sum.py', 'three_sum.tsv',
                                       has_three_sum))
