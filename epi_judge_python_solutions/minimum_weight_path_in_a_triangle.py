import functools
from typing import List

from test_framework import generic_test


def minimum_path_weight(triangle: List[List[int]]) -> int:

    min_weight_to_curr_row = [0]
    for row in triangle:
        min_weight_to_curr_row = [
            row[j] + min(
                min_weight_to_curr_row[max(j - 1, 0)],
                min_weight_to_curr_row[min(j,
                                           len(min_weight_to_curr_row) - 1)])
            for j in range(len(row))
        ]
    return min(min_weight_to_curr_row)


def minimum_path_weight_pythonic(triangle):
    return min(
        functools.reduce(
            lambda result, tri: [
                r + min(a, b) for r, a, b in zip(tri, [float('inf')] + result,
                                                 result + [float('inf')])
            ], triangle, [0]))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            'minimum_weight_path_in_a_triangle.py',
            'minimum_weight_path_in_a_triangle.tsv', minimum_path_weight))
