import collections
import functools
from typing import List

from test_framework import generic_test
from test_framework.test_utils import enable_executor_hook

Rect = collections.namedtuple('Rect', ('left', 'right', 'height'))


def compute_skyline(buildings: List[Rect]) -> List[Rect]:

    min_left = min(buildings, key=lambda b: b.left).left
    max_right = max(buildings, key=lambda b: b.right).right

    heights = [0] * (max_right - min_left + 1)
    for building in buildings:
        for i in range(building.left, building.right + 1):
            heights[i - min_left] = max(heights[i - min_left], building.height)

    result = []
    left = 0
    for i in range(1, len(heights)):
        if heights[i] != heights[i - 1]:
            result.append(
                Rect(left + min_left, i - 1 + min_left, heights[i - 1]))
            left = i
    return result + [Rect(left + min_left, max_right, heights[-1])]


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
