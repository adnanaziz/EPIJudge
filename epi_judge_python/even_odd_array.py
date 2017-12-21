import collections

from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook


def even_odd(A):
    # Implement this placeholder.
    return


@enable_timer_hook
def even_odd_wrapper(timer, A):
    before = collections.Counter(A)

    timer.start()
    even_odd(A)
    timer.stop()

    in_odd = False
    for a in A:
        if a % 2 == 0:
            if in_odd:
                raise TestFailureException("Even elements appear in odd part")
        else:
            in_odd = True
    after = collections.Counter(A)
    if before != after:
        raise TestFailureException("Elements mismatch")


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('even_odd_array.tsv',
                                              even_odd_wrapper)
