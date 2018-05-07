import itertools

from test_framework import generic_test


def number_of_ways(n, m):
    def compute_number_of_ways_to_xy(x, y):
        if x == y == 0:
            return 1

        if number_of_ways[x][y] == 0:
            ways_top = 0 if x == 0 else compute_number_of_ways_to_xy(x - 1, y)
            ways_left = 0 if y == 0 else compute_number_of_ways_to_xy(x, y - 1)
            number_of_ways[x][y] = ways_top + ways_left
        return number_of_ways[x][y]

    number_of_ways = [[0] * m for _ in range(n)]
    return compute_number_of_ways_to_xy(n - 1, m - 1)


def compute_number_of_ways_space_efficient(n, m):
    if n < m:
        n, m = m, n

    A = [1] * m
    for i in range(1, n):
        prev_res = 0
        for j in range(m):
            A[j] += prev_res
            prev_res = A[j]
    return A[m - 1]


# Pythonic implementation of space efficient solution.
def number_of_ways_pythonic(n, m):
    if n < m:
        n, m = m, n

    A = [1] * m
    for _ in range(1, n):
        A = list(itertools.accumulate(A))
    return A[-1]


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("number_of_traversals_matrix.py",
                                       'number_of_traversals_matrix.tsv',
                                       number_of_ways))
