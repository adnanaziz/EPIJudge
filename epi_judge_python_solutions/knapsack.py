import collections
import functools

from test_framework import generic_test
from test_framework.test_utils import enable_executor_hook

Item = collections.namedtuple('Item', ('weight', 'value'))


def optimum_subject_to_capacity(items, capacity):

    # Returns the optimum value when we choose from items[:k + 1] and have a
    # capacity of available_capacity.
    def optimum_subject_to_item_and_capacity(k, available_capacity):
        if k < 0:
            # No items can be chosen.
            return 0

        if V[k][available_capacity] == -1:
            without_curr_item = optimum_subject_to_item_and_capacity(
                k - 1, available_capacity)
            with_curr_item = (0 if available_capacity < items[k].weight else (
                items[k].value + optimum_subject_to_item_and_capacity(
                    k - 1, available_capacity - items[k].weight)))
            V[k][available_capacity] = max(without_curr_item, with_curr_item)
        return V[k][available_capacity]

    # V[i][j] holds the optimum value when we choose from items[:i + 1] and have
    # a capacity of j.
    V = [[-1] * (capacity + 1) for _ in items]
    return optimum_subject_to_item_and_capacity(len(items) - 1, capacity)


@enable_executor_hook
def optimum_subject_to_capacity_wrapper(executor, items, capacity):
    items = [Item(*i) for i in items]
    return executor.run(
        functools.partial(optimum_subject_to_capacity, items, capacity))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("knapsack.py", "knapsack.tsv",
                                       optimum_subject_to_capacity_wrapper))
