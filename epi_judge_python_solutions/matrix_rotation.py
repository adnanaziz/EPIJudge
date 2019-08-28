from typing import List

from test_framework import generic_test


def rotate_matrix(square_matrix: List[List[int]]) -> None:

    matrix_size = len(square_matrix) - 1
    for i in range(len(square_matrix) // 2):
        for j in range(i, matrix_size - i):
            # Perform a 4-way exchange. Note that A[~i] for i in [0, len(A) - 1]
            # is A[-(i + 1)].
            (square_matrix[i][j], square_matrix[~j][i], square_matrix[~i][~j],
             square_matrix[j][~i]) = (square_matrix[~j][i],
                                      square_matrix[~i][~j],
                                      square_matrix[j][~i],
                                      square_matrix[i][j])


def rotate_matrix_wrapper(square_matrix):
    rotate_matrix(square_matrix)
    return square_matrix


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('matrix_rotation.py',
                                       'matrix_rotation.tsv',
                                       rotate_matrix_wrapper))
