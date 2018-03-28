import collections
import functools
from sys import exit

from test_framework import generic_test, test_utils
from test_framework.test_utils import enable_executor_hook

Rectangle = collections.namedtuple('Rectangle', ('left', 'right', 'height'))


def compute_skyline(buildings):
    # Implement this placeholder.
    return []


@enable_executor_hook
def compute_skyline_wrapper(executor, buildings):
    buildings = [Rectangle(*x) for x in buildings]

    result = executor.run(functools.partial(compute_skyline, buildings))

    return [(x.left, x.right, x.height) for x in result]


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('drawing_skyline.tsv',
                                       compute_skyline_wrapper))
