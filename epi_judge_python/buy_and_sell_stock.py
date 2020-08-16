# given an array prices: List[float] of length n_prices
# create an array points of Points, which have price and day attributes (length n_points = n_prices)
# sort points by price ascending
# max price_delta is guarantee to be points[n_points - 1].price - points[0].price
# but points[n_points - 1].day may be < points[0].day
# say n_points = 10
# second greatest price_delta is (price_9 - price_1) OR (price_8 - price_0)
# given second greatest price_delta is (price_8 - price_0)
# third is (price_9 - price_1) OR (price_8 - price_1) OR (price_7 - price_0)
# given second greatest price_delta is (price_8 - price_1)
# fourth is (price_9 - price_1) OR (price_8 - price_2) OR (price_7 - price_0)
# maybe check (price_7 - price_1) also for simplicity
# looks O(n_points^2)

# Test 1
# Input: [100., 90., 80., 70., 71., 60., 50., 40., 30.]
# Output: 1.
# Q: worst case can be better than O(N^2)?

# Test 2
# Input: [3,2,1]
# Output: 0

# Test 3: [10] -> 0
# test 4: [] -> 0
# test 5: [10, 20, 30] -> 10

from typing import List, Tuple
from test_framework import generic_test

# for a prices list of length N runtime O(N**2) memory O(1)
def buy_and_sell_stock_once_brute(prices: List[float]) -> float:
    # brute force & correctness
    n_prices = len(prices)
    max_profit = 0.0  # initialize

    for i in range(n_prices):
        for j in range(i+1, n_prices):
            max_profit = max(max_profit, prices[j] - prices[i])

    return max_profit

# returns (max_profit_left, max_profit_right, min_price_left_left,
# max_price_left_left, min_price_right_right, max_price_right_right)
# for the left prices[start:middle] and right prices[middle:end]
def stock_helper(prices: List[float], start: int, middle: int, end: int)\
    -> Tuple[float, float, float, float, float, float]:
    # nit: Prices class with instance attributes MAX_PRICE and MIN_PRICE

    # base cases
    if (end - start) <= 0 or (start < 0) or (len(prices) < end)\
        or (middle < start) or (end < middle):  # length 0 or undefined
        return (0.0, 0.0, float(2**31 - 1), float(2**31 - 1), 0.0, 0.0)
    if (end - start) <= 2:  # length 1 or length 2 slice prices[start:end]
        return (0.0, 0.0, prices[start], prices[start], prices[end-1], prices[end-1])

    (profit_ll, profit_lr, min_ll, max_ll, min_lr, max_lr) = stock_helper(
        prices,
        start,
        int((start + middle) / 2),
        middle
    )
    (profit_rl, profit_rr, min_rl, max_rl, min_rr, max_rr) = stock_helper(
        prices,
        middle,
        int((end + middle) / 2),
        end
    )

    max_profit_left = max([profit_ll, profit_lr, max_lr - min_ll])
    max_profit_right = max([profit_rl, profit_rr, max_rr - min_rl])
    min_l = min(min_ll, min_lr)
    max_l = max(max_ll, max_lr)
    min_r = min(min_rl, min_rr)
    max_r = max(max_rl, max_rr)

    return (max_profit_left, max_profit_right, min_l, max_l, min_r, max_r)

# for a prices list of length N runtime O(N logN) memory O(N logN)
# runtime cost model: number of  calls to stock_helper
# memory: interpreter must keepe open frames for funciton calls unitl they return
# at peek, this is N*logN frames open at deepest point of recursion
def buy_and_sell_stock_once(prices: List[float]) -> float:
    # efficient & correctness
    n_prices = len(prices)
    max_profit_left, max_profit_right, min_l, max_l, min_r, max_r = stock_helper(
        prices,
        0,
        int(n_prices / 2),
        n_prices
    )

    max_profit = max([max_profit_left, max_profit_right, max_r - min_l])
    return max_profit

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('buy_and_sell_stock.py',
                                       'buy_and_sell_stock.tsv',
                                       buy_and_sell_stock_once))

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('buy_and_sell_stock.py',
                                       'buy_and_sell_stock.tsv',
                                       buy_and_sell_stock_once))
