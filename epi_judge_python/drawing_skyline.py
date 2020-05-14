import collections
import functools
from typing import List

from test_framework import generic_test
from test_framework.test_utils import enable_executor_hook

Rect = collections.namedtuple('Rect', ('left', 'right', 'height'))


def compute_skyline(buildings: List[Rect]) -> List[Rect]:
    # TODO - you fill in here.
    return []


@enable_executor_hook
def compute_skyline_wrapper(executor, buildings):
    buildings = [Rect(*x) for x in buildings]

    result = executor.run(functools.partial(compute_skyline, buildings))

    return [(x.left, x.right, x.height) for x in result]


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('drawing_skyline.py',
                                       'drawing_skyline.tsv',
                                       compute_skyline_wrapper))
