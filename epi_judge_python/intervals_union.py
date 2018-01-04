from test_framework.test_utils import enable_timer_hook
import collections

Endpoint = collections.namedtuple('Endpoint', ('is_closed', 'val'))

Interval = collections.namedtuple('Interval', ('left', 'right'))


def union_of_intervals(intervals):
    # Implement this placeholder.
    return []


@enable_timer_hook
def union_of_intervals_wrapper(timer, A):
    A = [Interval(Endpoint(x[1], x[0]), Endpoint(x[3], x[2])) for x in A]

    timer.start()
    result = union_of_intervals(A)
    timer.stop()

    return [(i.left.val, i.left.is_closed, i.right.val, i.right.is_closed)
            for i in result]


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main("intervals_union.tsv",
                                              union_of_intervals_wrapper)
