import collections

from test_framework import generic_test


def max_square_submatrix(A):

    MaxHW = collections.namedtuple('MaxHW', ('h', 'w'))
    # DP table stores (h, w) for each (i, j).
    table = [[None] * len(A[0]) for _ in A]
    for i, row in reversed(list(enumerate(A))):
        for j, v in reversed(list(enumerate(row))):
            # Finds the largest h such that (i, j) to (i + h - 1, j) are feasible.
            # Finds the largest w such that (i, j) to (i, j + w - 1) are feasible.
            table[i][j] = (MaxHW(table[i + 1][j].h + 1 if i + 1 < len(A) else
                                 1, table[i][j + 1].w + 1
                                 if j + 1 < len(row) else 1)
                           if v else MaxHW(0, 0))

    # A table stores the length of the largest square for each (i, j).
    s = [[0] * len(A[0]) for _ in A]
    max_square_area = 0
    for i, row in reversed(list(enumerate(A))):
        for j, v in reversed(list(enumerate(row))):
            if v:
                side = min(table[i][j].h, table[i][j].w)
                # Gets the length of largest square with bottom-left corner (i,
                # j).
                if i + 1 < len(A) and j + 1 < len(A[i + 1]):
                    side = min(s[i + 1][j + 1] + 1, side)
                s[i][j] = side
                max_square_area = max(max_square_area, side**2)
    return max_square_area


def max_square_submatrix_space_efficient(A):
    pre = [0] * len(A[0])
    max_side = 0
    for row in A:
        for j, v in enumerate(row[1:], 1):
            row[j] *= min(pre[j - 1], pre[j], row[j - 1]) + 1
        max_side = max(max_side, max(row))
        pre = row
    return max_side**2


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("max_square_submatrix.py",
                                       'max_square_submatrix.tsv',
                                       max_square_submatrix))
