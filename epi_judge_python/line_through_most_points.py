import collections
import functools
from typing import List

from test_framework import generic_test
from test_framework.test_utils import enable_executor_hook

Point = collections.namedtuple('Point', ('x', 'y'))


def find_line_with_most_points(points: List[Point]) -> int:
    # TODO - you fill in here.
    return 0


@enable_executor_hook
def find_line_with_most_points_wrapper(executor, points):
    points = [Point(*x) for x in points]
    return executor.run(functools.partial(find_line_with_most_points, points))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('line_through_most_points.py',
                                       'line_through_most_points.tsv',
                                       find_line_with_most_points_wrapper))
