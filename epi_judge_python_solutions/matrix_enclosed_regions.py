import collections
from typing import List

from test_framework import generic_test


def fill_surrounded_regions(board: List[List[str]]) -> None:

    n, m = len(board), len(board[0])
    q = collections.deque([(i, j) for k in range(n)
                           for i, j in ((k, 0), (k, m - 1))] +
                          [(i, j) for k in range(m)
                           for i, j in ((0, k), (n - 1, k))])
    while q:
        x, y = q.popleft()
        if 0 <= x < n and 0 <= y < m and board[x][y] == 'W':
            board[x][y] = 'T'
            q.extend([(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)])
    board[:] = [['B' if c != 'T' else 'W' for c in row] for row in board]


def fill_surrounded_regions_wrapper(board):
    fill_surrounded_regions(board)
    return board


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('matrix_enclosed_regions.py',
                                       'matrix_enclosed_regions.tsv',
                                       fill_surrounded_regions_wrapper))
