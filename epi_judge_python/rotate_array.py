import functools
from sys import exit

from test_framework import generic_test, test_utils
from test_framework.test_utils import enable_executor_hook


def rotate_array(rotate_amount, A):
    # Implement this placeholder.
    return


@enable_executor_hook
def rotate_array_wrapper(executor, A, rotate_amount):
    a_copy = A[:]
    executor.run(functools.partial(rotate_array, rotate_amount, a_copy))
    return a_copy


if __name__ == '__main__':
    # The timeout is set to 30 seconds.
    # If your program ends with TIMEOUT error probably it stuck in an infinity loop,
    # You can extend the limit by changing the following line.
    timeout_seconds = 30

    exit(
        generic_test.generic_test_main(timeout_seconds, 'rotate_array.tsv',
                                       rotate_array_wrapper))
