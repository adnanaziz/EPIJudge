from test_framework import generic_test


def buy_and_sell_stock_once(prices):
    cur_min, profit = float('inf'), 0
    for price in prices:
        profit = max(profit, price - cur_min)
        cur_min = min(cur_min, price)
    return profit


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("buy_and_sell_stock.py",
                                       "buy_and_sell_stock.tsv",
                                       buy_and_sell_stock_once))
