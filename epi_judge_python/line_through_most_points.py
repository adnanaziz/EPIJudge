import collections
import functools
from sys import exit

from test_framework import generic_test, test_utils
from test_framework.test_utils import enable_executor_hook

Point = collections.namedtuple("Point", ("x", "y"))


def find_line_with_most_points(points):
    # Implement this placeholder.
    return 0


@enable_executor_hook
def find_line_with_most_points_wrapper(executor, points):
    points = [Point(*x) for x in points]
    return executor.run(functools.partial(find_line_with_most_points, points))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('line_through_most_points.tsv',
                                       find_line_with_most_points_wrapper))
