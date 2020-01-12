import collections
import functools
import math
from typing import DefaultDict, List, Tuple

from test_framework import generic_test
from test_framework.test_utils import enable_executor_hook

Point = collections.namedtuple('Point', ('x', 'y'))


def find_line_with_most_points(points: List[Point]) -> int:

    result = 0
    for i, p1 in enumerate(points):
        slope_table: DefaultDict[Tuple[int, int],
                                 int] = collections.defaultdict(int)
        overlap_points = 1
        for p2 in points[i + 1:]:
            if p1 == p2:
                overlap_points += 1
            elif p1.x == p2.x:
                # A vertical line with slope 1/0.
                slope_table[(0, 1)] += 1
            else:
                x_diff, y_diff = p1.x - p2.x, p1.y - p2.y
                gcd = math.gcd(x_diff, y_diff)
                x_diff, y_diff = x_diff / gcd, y_diff / gcd
                if x_diff < 0:
                    x_diff, y_diff = -x_diff, -y_diff
                slope_table[(x_diff, y_diff)] += 1
        result = max(result,
                     overlap_points + max(slope_table.values(), default=0))
    return result


@enable_executor_hook
def find_line_with_most_points_wrapper(executor, points):
    points = [Point(*x) for x in points]
    return executor.run(functools.partial(find_line_with_most_points, points))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('line_through_most_points.py',
                                       'line_through_most_points.tsv',
                                       find_line_with_most_points_wrapper))
