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


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('minimum_points_covering_intervals.tsv',
                                   find_minimum_visits_wrapper)
