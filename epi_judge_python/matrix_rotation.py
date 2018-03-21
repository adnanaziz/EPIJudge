def rotate_matrix(square_matrix):
    # Implement this placeholder.
    return


def rotate_matrix_wrapper(square_matrix):
    rotate_matrix(square_matrix)
    return square_matrix


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('matrix_rotation.tsv',
                                       rotate_matrix_wrapper))
