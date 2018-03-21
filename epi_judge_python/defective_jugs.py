import collections
import functools
from sys import exit

from test_framework import generic_test, test_utils
from test_framework.test_utils import enable_executor_hook

Jug = collections.namedtuple('Jug', ('low', 'high'))


def check_feasible(jugs, L, H, c=set()):
    # Implement this placeholder.
    return True


@enable_executor_hook
def check_feasible_wrapper(executor, A, l, h):
    A = [Jug(*x) for x in A]
    return executor.run(functools.partial(check_feasible, A, l, h))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('defective_jugs.tsv',
                                       check_feasible_wrapper))
