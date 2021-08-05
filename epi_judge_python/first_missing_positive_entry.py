from typing import List

from test_framework import generic_test


def find_first_missing_positive(A: List[int]) -> int:
    n = len(A)
    for i in range(n):
        while 1 <= A[i] <= n and A[i] != A[A[i]-1]:
            b = A[i] - 1
            A[i], A[b] = A[b], A[i]

    for i in range(n):
        if A[i] != i + 1:
            return i + 1

    return n + 1


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('first_missing_positive_entry.py',
                                       'first_missing_positive_entry.tsv',
                                       find_first_missing_positive))
