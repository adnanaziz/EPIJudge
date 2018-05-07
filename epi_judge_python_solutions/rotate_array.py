import functools

from test_framework import generic_test
from test_framework.test_utils import enable_executor_hook


def rotate_array(rotate_amount, A):

    rotate_amount %= len(A)

    def reverse(begin, end):
        while begin < end:
            A[begin], A[end] = A[end], A[begin]
            begin, end = begin + 1, end - 1

    reverse(0, len(A) - 1)
    reverse(0, rotate_amount - 1)
    reverse(rotate_amount, len(A) - 1)


# Although the following function is very natural way to rotate an array,
# its use of sublists leads to copy from original list, and therefore
# linear space complexity.
def rotate_array_naive(rotate_amount, A):
    rotate_amount %= len(A)
    A[:] = A[::-1]  # reverse whole list
    A[:rotate_amount] = A[:rotate_amount][::
                                          -1]  # reverse A[:rotate_amount] part
    A[rotate_amount:] = A[rotate_amount:][::
                                          -1]  # reverse A[rotate_amount:] part


@enable_executor_hook
def rotate_array_wrapper(executor, A, rotate_amount):
    a_copy = A[:]
    executor.run(functools.partial(rotate_array, rotate_amount, a_copy))
    return a_copy


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("rotate_array.py", 'rotate_array.tsv',
                                       rotate_array_wrapper))
