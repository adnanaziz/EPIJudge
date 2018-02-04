import collections

from test_framework.test_utils import enable_timer_hook

Point = collections.namedtuple("Point", ("x", "y"))


def find_line_with_most_points(points):
    # Implement this placeholder.
    return 0


@enable_timer_hook
def find_line_with_most_points_wrapper(timer, points):
    points = [Point(*x) for x in points]
    timer.start()
    return find_line_with_most_points(points)


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('line_though_most_points.tsv',
                                   find_line_with_most_points_wrapper)
