def fill_surrounded_regions(board):
    # Implement this placeholder.
    return


def fill_surrounded_regions_wrapper(board):
    fill_surrounded_regions(board)
    return board


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('matrix_enclosed_regions.tsv',
                                       fill_surrounded_regions_wrapper))
