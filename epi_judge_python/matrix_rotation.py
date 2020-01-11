from typing import List

from test_framework import generic_test


def rotate_matrix(square_matrix: List[List[int]]) -> None:
    # TODO - you fill in here.
    return


def rotate_matrix_wrapper(square_matrix):
    rotate_matrix(square_matrix)
    return square_matrix


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('matrix_rotation.py',
                                       'matrix_rotation.tsv',
                                       rotate_matrix_wrapper))
