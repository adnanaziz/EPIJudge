import collections

from test_framework.test_utils import enable_timer_hook

Jug = collections.namedtuple('Jug', ('low', 'high'))


def check_feasible(jugs, L, H, c=set()):
    # Implement this placeholder.
    return True


@enable_timer_hook
def check_feasible_wrapper(timer, A, l, h):
    A = [Jug(*x) for x in A]
    timer.start()
    return check_feasible(A, l, h)


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('defective_jugs.tsv',
                                   check_feasible_wrapper)
