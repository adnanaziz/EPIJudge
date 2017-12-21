def rotate_matrix(square_matrix):
    # Implement this placeholder.
    return


def rotate_matrix_wrapper(A):
    rotate_matrix(A)
    return A


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('matrix_rotation.tsv',
                                              rotate_matrix_wrapper)
