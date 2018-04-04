from sys import exit

from test_data_generators.test_explanation import TestExplanation
from test_framework import generic_test, test_utils

explanation = TestExplanation()


def buy_and_sell_stock_once(prices):
    min_price_so_far, max_profit = float('inf'), 0.0
    for price in prices:
        max_profit_sell_today = price - min_price_so_far
        max_profit = max(max_profit, max_profit_sell_today)
        if max_profit == max_profit_sell_today:
            explanation.buy = min_price_so_far
            explanation.sell = price
        min_price_so_far = min(min_price_so_far, price)
    return max_profit


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("buy_and_sell_stock.tsv",
                                       buy_and_sell_stock_once))
