import collections

from test_framework.test_utils import enable_timer_hook

Rectangle = collections.namedtuple('Rectangle', ('left', 'right', 'height'))


def compute_skyline(buildings):
    # Implement this placeholder.
    return []


@enable_timer_hook
def compute_skyline_wrapper(timer, buildings):
    buildings = [Rectangle(*x) for x in buildings]

    timer.start()
    result = compute_skyline(buildings)
    timer.stop()

    return [(x.left, x.right, x.height) for x in result]


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('drawing_skyline.tsv',
                                   compute_skyline_wrapper)
