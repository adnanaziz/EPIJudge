def rotate_array(i, A):
    # Implement this placeholder.
    return


def rotate_array_wrapper(a, k):
    rotate_array(k, a)
    return a


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('rotate_array.tsv',
                                              rotate_array_wrapper)
