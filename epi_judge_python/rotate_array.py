from test_framework.test_utils import enable_timer_hook


def rotate_array(rotate_amount, A):
    # Implement this placeholder.
    return


@enable_timer_hook
def rotate_array_wrapper(timer, A, rotate_amount):
    a_copy = A[:]
    timer.start()
    rotate_array(rotate_amount, a_copy)
    timer.stop()
    return a_copy


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('rotate_array.tsv', rotate_array_wrapper)
