from test_framework import generic_test


def buy_and_sell_stock_twice(prices):
    total_profit = 0.0
    min_price_seen = float('inf')
    profits = [0.0] * len(prices)
    for i, price in enumerate(prices):
        min_price_seen = min(min_price_seen, price)
        total_profit = max(total_profit, price - min_price_seen)
        profits[i] = total_profit

    max_price_seen = float('-inf')
    for i, price in reversed(list(enumerate(prices[1:], 1))):
        max_price_seen = max(max_price_seen, price)
        total_profit = max(total_profit, max_price_seen - price + profits[i-1])
    return total_profit


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("buy_and_sell_stock_twice.py",
                                       "buy_and_sell_stock_twice.tsv",
                                       buy_and_sell_stock_twice))
