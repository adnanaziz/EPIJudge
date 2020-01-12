import functools
import itertools
from typing import List

from test_framework import generic_test


def maximum_revenue(coins: List[int]) -> int:
    @functools.lru_cache(None)
    def compute_maximum_revenue_for_range(a, b):
        if a > b:
            # No coins left.
            return 0

        max_revenue_a = coins[a] + min(
            compute_maximum_revenue_for_range(a + 2, b),
            compute_maximum_revenue_for_range(a + 1, b - 1))
        max_revenue_b = coins[b] + min(
            compute_maximum_revenue_for_range(a + 1, b - 1),
            compute_maximum_revenue_for_range(a, b - 2))
        return max(max_revenue_a, max_revenue_b)

    return compute_maximum_revenue_for_range(0, len(coins) - 1)


def maximum_revenue_alternative(coins):
    @functools.lru_cache(None)
    def compute_maximum_revenue_for_range(a, b):
        if a > b:
            return 0
        elif a == b:
            return coins[a]

        return max(
            coins[a] + prefix_sum[b] - (prefix_sum[a] if a + 1 > 0 else 0) -
            compute_maximum_revenue_for_range(a + 1, b), coins[b] +
            prefix_sum[b - 1] - (prefix_sum[a - 1] if a > 0 else 0) -
            compute_maximum_revenue_for_range(a, b - 1))

    prefix_sum = list(itertools.accumulate(coins))
    return compute_maximum_revenue_for_range(0, len(coins) - 1)


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('picking_up_coins.py',
                                       'picking_up_coins.tsv',
                                       maximum_revenue))
