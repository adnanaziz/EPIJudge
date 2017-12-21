import collections

from test_framework.test_utils import enable_timer_hook

Interval = collections.namedtuple('Interval', ('left', 'right'))


def find_minimum_visits(intervals):
    # Implement this placeholder.
    return 0


@enable_timer_hook
def find_minimum_visits_wrapper(timer, A):
    A = [Interval(*a) for a in A]
    timer.start()
    return find_minimum_visits(A)


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('points_covering_intervals.tsv',
                                              find_minimum_visits_wrapper)
