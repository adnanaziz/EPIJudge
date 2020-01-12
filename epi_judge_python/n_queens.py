from typing import List

from test_framework import generic_test


def n_queens(n: int) -> List[List[int]]:
    # TODO - you fill in here.
    return []


def comp(a, b):
    return sorted(a) == sorted(b)


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('n_queens.py', 'n_queens.tsv', n_queens,
                                       comp))
