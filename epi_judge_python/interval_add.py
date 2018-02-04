import collections

from test_framework.test_utils import enable_timer_hook

Interval = collections.namedtuple('Interval', ('left', 'right'))


def add_interval(disjoint_intervals, new_interval):
    # Implement this placeholder.
    return []


@enable_timer_hook
def add_interval_wrapper(timer, disjoint_intervals, new_interval):
    disjoint_intervals = [Interval(*x) for x in disjoint_intervals]
    timer.start()
    return add_interval(disjoint_intervals, Interval(*new_interval))


def res_printer(expected, result):
    def fmt(x):
        return [[e[0], e[1]] for e in x] if x else None

    return fmt(expected), fmt(result)


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main(
        'interval_add.tsv', add_interval_wrapper, res_printer=res_printer)
