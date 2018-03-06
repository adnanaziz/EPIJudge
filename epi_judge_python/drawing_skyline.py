import collections
import functools

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


from sys import exit
from test_framework import generic_test, test_utils

if __name__ == '__main__':
    # The timeout is set to 30 seconds.
    # If your program ends with TIMEOUT error probably it stuck in an infinity loop,
    # You can extend the limit by changing the following line.
    timeout_seconds = 30

    exit(
        generic_test.generic_test_main(timeout_seconds, 'drawing_skyline.tsv',
                                       compute_skyline_wrapper))
