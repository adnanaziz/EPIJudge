import functools
import itertools

from test_framework import generic_test


def number_of_ways(n: int, m: int) -> int:
    @functools.lru_cache(None)
    def compute_number_of_ways_to_xy(x, y):
        if x == y == 0:
            return 1

        ways_top = 0 if x == 0 else compute_number_of_ways_to_xy(x - 1, y)
        ways_left = 0 if y == 0 else compute_number_of_ways_to_xy(x, y - 1)
        return ways_top + ways_left

    return compute_number_of_ways_to_xy(n - 1, m - 1)


def number_of_ways_space_efficient(n, m):
    if n < m:
        n, m = m, n

    table = [1] * m
    for i in range(1, n):
        prev_res = 0
        for j in range(m):
            table[j] += prev_res
            prev_res = table[j]
    return table[m - 1]


# Pythonic implementation of space efficient solution.
def number_of_ways_pythonic(n, m):
    if n < m:
        n, m = m, n

    table = [1] * m
    for _ in range(1, n):
        table = list(itertools.accumulate(table))
    return table[-1]


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('number_of_traversals_matrix.py',
                                       'number_of_traversals_matrix.tsv',
                                       number_of_ways))
