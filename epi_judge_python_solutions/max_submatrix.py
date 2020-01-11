import collections
from typing import List, cast

from test_framework import generic_test


def max_rectangle_submatrix(A: List[List[bool]]) -> int:

    MaxHW = collections.namedtuple('MaxHW', ('h', 'w'))
    # DP table stores (h, w) for each (i, j).
    table = [[MaxHW(0, 0)] * len(A[0]) for _ in A]

    for i, row in reversed(list(enumerate(A))):
        for j, v in reversed(list(enumerate(row))):
            # Find the largest h such that (i, j) to (i + h - 1, j) are feasible.
            # Find the largest w such that (i, j) to (i, j + w - 1) are feasible.
            table[i][j] = (MaxHW(
                table[i + 1][j].h +
                1 if i + 1 < len(A) else 1, table[i][j + 1].w +
                1 if j + 1 < len(row) else 1) if v else MaxHW(0, 0))

    max_rectangle_area = 0
    for i, row in enumerate(A):
        for j, v in enumerate(row):
            # Process (i, j) if it is feasible and is possible to update
            # max_rectangle_area.
            if v and table[i][j].w * table[i][j].h > max_rectangle_area:
                min_width = float('inf')
                for a in range(table[i][j].h):
                    min_width = cast(int, min(min_width, table[i + a][j].w))
                    max_rectangle_area = max(max_rectangle_area,
                                             min_width * (a + 1))
    return max_rectangle_area


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('max_submatrix.py', 'max_submatrix.tsv',
                                       max_rectangle_submatrix))
