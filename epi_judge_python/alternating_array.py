import functools

from test_framework.test_failure import TestFailure
from test_framework.test_utils import enable_executor_hook


def rearrange(A):
    # Implement this placeholder.
    return


@enable_executor_hook
def rearrange_wrapper(executor, A):
    def check_answer(A):
        for i in range(len(A)):
            if i % 2:
                if A[i] < A[i - 1]:
                    raise TestFailure(
                        '{}th element ({}) shall be greater than or equal to {}th element ({})'.
                        format(i, A[i], i - 1, A[i - 1]))
                if i + 1 < len(A):
                    if A[i] < A[i + 1]:
                        raise TestFailure(
                            '{}th element ({}) shall be greater than or equal to {}th element ({})'.
                            format(i, A[i], i + 1, A[i + 1]))
            else:
                if i > 0:
                    if A[i - 1] < A[i]:
                        raise TestFailure(
                            '{}th element ({}) shall be greater than or equal to {}th element ({})'.
                            format(i - 1, A[i - 1], i, A[i]))
                if i + 1 < len(A):
                    if A[i + 1] < A[i]:
                        raise TestFailure(
                            '{}th element ({}) shall be greater than or equal to {}th element ({})'.
                            format(i + 1, A[i + 1], i, A[i]))

    executor.run(functools.partial(rearrange, A))
    check_answer(A)


from sys import exit
from test_framework import generic_test, test_utils

if __name__ == '__main__':
    # The timeout is set to 30 seconds.
    # If your program ends with TIMEOUT error probably it stuck in an infinity loop,
    # You can extend the limit by changing the following line.
    timeout_seconds = 30

    exit(
        generic_test.generic_test_main(
            timeout_seconds, 'alternating_array.tsv', rearrange_wrapper))
