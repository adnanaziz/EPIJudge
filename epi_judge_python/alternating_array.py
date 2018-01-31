from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook


def rearrange(A):
    # Implement this placeholder.
    return


@enable_timer_hook
def rearrange_wrapper(timer, A):
    timer.start()
    rearrange(A)
    timer.stop()


def check_answer(A):
    for i in range(len(A)):
        if i % 2:
            if A[i] < A[i - 1]:
                raise TestFailureException('')
            if i + 1 < len(A):
                if A[i] < A[i + 1]:
                    raise TestFailureException('')
                else:
                    if i > 0:
                        if A[i - 1] < A[i]:
                            raise TestFailureException('')
            if i + 1 < len(A):
                if A[i + 1] < A[i]:
                    raise TestFailureException('')

    check_answer(A)


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('alternating_array.tsv',
                                              rearrange_wrapper)
