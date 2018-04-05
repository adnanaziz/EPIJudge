import collections
import functools
from sys import exit

from test_framework import generic_test, test_utils
from test_framework.test_utils import enable_executor_hook

Jug = collections.namedtuple('Jug', ('low', 'high'))


def check_feasible(jugs, L, H, c=set()):
    VolumeRange = collections.namedtuple('VolumeRange', ('low', 'high'))
    if L > H or VolumeRange(L, H) in c or (L < 0 and H < 0):
        return False

    # Checks the volume for each jug to see if it is possible.
    if any((L <= j.low and j.high <= H)
           or check_feasible(jugs, L - j.low, H - j.high) for j in jugs):
        return True
    c.add(VolumeRange(L, H))  # Marks this as impossible.
    return False


@enable_executor_hook
def check_feasible_wrapper(executor, A, l, h):
    A = [Jug(*x) for x in A]
    return executor.run(functools.partial(check_feasible, A, l, h))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('defective_jugs.tsv',
                                       check_feasible_wrapper))
