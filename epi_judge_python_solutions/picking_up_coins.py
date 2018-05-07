import itertools

from test_framework import generic_test


def maximum_revenue(coins):
    def compute_maximum_revenue_for_range(a, b):
        if a > b:
            # No coins left.
            return 0

        if maximum_revenue_for_range[a][b] == 0:
            max_revenue_a = coins[a] + min(
                compute_maximum_revenue_for_range(a + 2, b),
                compute_maximum_revenue_for_range(a + 1, b - 1))
            max_revenue_b = coins[b] + min(
                compute_maximum_revenue_for_range(a + 1, b - 1),
                compute_maximum_revenue_for_range(a, b - 2))
            maximum_revenue_for_range[a][b] = max(max_revenue_a, max_revenue_b)
        return maximum_revenue_for_range[a][b]

    maximum_revenue_for_range = [[0] * len(coins) for _ in coins]
    return compute_maximum_revenue_for_range(0, len(coins) - 1)


def maximum_revenue_alternative(coins):
    def maximum_revenue_alternative_helper(a, b):
        if a > b:
            return 0
        elif a == b:
            return coins[a]

        if maximum_revenue_for_range[a][b] == -1:
            maximum_revenue_for_range[a][b] = max(
                coins[a] + prefix_sum[b] - (prefix_sum[a]
                                            if a + 1 > 0 else 0) -
                maximum_revenue_alternative_helper(a + 1, b),
                coins[b] + prefix_sum[b - 1] - (prefix_sum[a - 1]
                                                if a > 0 else 0) -
                maximum_revenue_alternative_helper(a, b - 1))
        return maximum_revenue_for_range[a][b]

    prefix_sum = list(itertools.accumulate(coins))
    maximum_revenue_for_range = [[-1] * len(coins) for _ in coins]
    return maximum_revenue_alternative_helper(0, len(coins) - 1)


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            "picking_up_coins.py", 'picking_up_coins.tsv', maximum_revenue))
