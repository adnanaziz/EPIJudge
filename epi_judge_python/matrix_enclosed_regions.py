from typing import List

from test_framework import generic_test


def fill_surrounded_regions(board: List[List[str]]) -> None:
    # TODO - you fill in here.
    return


def fill_surrounded_regions_wrapper(board):
    fill_surrounded_regions(board)
    return board


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('matrix_enclosed_regions.py',
                                       'matrix_enclosed_regions.tsv',
                                       fill_surrounded_regions_wrapper))
