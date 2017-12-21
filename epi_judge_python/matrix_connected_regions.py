def flip_color(x, y, A):
    # Implement this placeholder.
    return


def flip_color_wrapper(x, y, a):
    flip_color(x, y, a)
    return a


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('painting.tsv',
                                              flip_color_wrapper)
