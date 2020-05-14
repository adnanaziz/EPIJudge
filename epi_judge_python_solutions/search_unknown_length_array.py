from typing import List

from test_framework import generic_test


def binary_search_unknown_length(A: List[int], k: int) -> int:

    # Find the possible range where k exists.
    p = 0
    while True:
        try:
            idx = (1 << p) - 1  # 2^p - 1.
            if A[idx] == k:
                return idx
            elif A[idx] > k:
                break
        except IndexError:
            break
        p += 1

    # Binary search between indices 2^(p - 1) and 2^p - 2, inclusive.
    left, right = 1 << max(0, (p - 1)), (1 << p) - 2
    while left <= right:
        mid = left + (right - left) // 2
        try:
            if A[mid] == k:
                return mid
            elif A[mid] > k:
                right = mid - 1
            else:  # A[mid] < k
                left = mid + 1
        except IndexError:
            right = mid - 1  # Search the left part if out-of-bound.
    return -1  # Nothing matched k.


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('search_unknown_length_array.py',
                                       'search_unknown_length_array.tsv',
                                       binary_search_unknown_length))
