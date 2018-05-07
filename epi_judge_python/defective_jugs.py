import collections
import functools

from test_framework import generic_test
from test_framework.test_utils import enable_executor_hook

Jug = collections.namedtuple('Jug', ('low', 'high'))


def check_feasible(jugs, L, H):
    # TODO - you fill in here.
    return True


@enable_executor_hook
def check_feasible_wrapper(executor, jugs, l, h):
    jugs = [Jug(*x) for x in jugs]
    return executor.run(functools.partial(check_feasible, jugs, l, h))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            "defective_jugs.py", 'defective_jugs.tsv', check_feasible_wrapper))
