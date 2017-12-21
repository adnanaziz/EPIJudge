import collections

from test_framework.test_utils import enable_timer_hook

Item = collections.namedtuple('Item', ('weight', 'value'))


def optimum_subject_to_capacity(items, capacity):
    # Implement this placeholder.
    return 0


@enable_timer_hook
def optimum_subject_to_capacity_wrapper(timer, items, capacity):
    items = [Item(*i) for i in items]
    timer.start()
    return optimum_subject_to_capacity(items, capacity)


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main(
        "knapsack.tsv", optimum_subject_to_capacity_wrapper)
