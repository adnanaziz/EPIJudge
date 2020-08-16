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

from typing import List, Set, Tuple, Union

from test_framework import generic_test

from collections import namedtuple
#Point = namedtuple("Point", ("price", "day", "rank"))  # subclass of Tuple
#PointPair = namedtuple("PointPair", ("profit", "start_point", "end_point"))
import heapq
from heapq import heappush, heappop
from functools import total_ordering

def buy_and_sell_stock_once_brute(prices: List[float]) -> float:
    # brute force & correctness
    n_prices = len(prices)
    max_profit = 0.0  # initialize

    for i in range(n_prices):
        for j in range(i+1, n_prices):
            max_profit = max(max_profit, prices[j] - prices[i])

    return max_profit

@total_ordering
class Point:
    price: float
    day: int
    rank: Union[int, None]

    def __init__(self, price, day):
        self.price = price
        self.day = day
        self.rank = None

    def __eq__(self, point: 'Point'):
        return (self.day == point.day) and (self.price == point.price)

    def __hash__(self):
        return hash((self.price, self.day))

    def __lt__(self, point: 'Point'):
        return (self.price, self.day) < (point.price, point.day)

    def __str__(self):
        return str((self.price, self.day))

# returns the profit of buying at start and selling at end
# does NOT check for validity (start.day < end.day)
def get_price_delta(start: Point, end: Point):
    return end.price - start.price

# returns positive profit if exists, otherwise None
def get_profit(start: Point, end: Point) -> Union[float, None]:
    if (end.day <= start.day) or (end.price <= start.price):
        return None
    return get_price_delta(start, end)

@total_ordering
class PointPair:
    start: Point
    end: Point
    price_delta: float
    profit: Union[float, None]

    def __init__(self, start: Point, end: Point):
        self.start = start
        self.end = end
        self.price_delta = get_price_delta(start, end)
        self.profit = get_profit(start, end)

    def __hash__(self):
        # point is of type tuple (price, day, rank)
        # PointPairs are unique to the pair
        return hash((self.start, self.end))

    # PointPair price_delta attribute is used for comparison
    def __eq__(self, pp: 'PointPair'):
        if not isinstance(pp, PointPair):
            raise TypeError("Point can only be compared to another Point")

        return (self.start == pp.start) and (self.end == pp.end)

    # self < pp iff self.price_delta > pp.price_delta
    # this is an awkward comparison special method needed for max heap
    def __lt__(self, pp: 'PointPair'):
        if not isinstance(pp, PointPair):
            raise TypeError("Point can only be compared to another Point")

        return (self.price_delta > pp.price_delta)  # see above comment

    def __str__(self):
        return "(" + str(self.start) + ", " + str(self.end) + ")"

def buy_and_sell_stock_once(prices: List[float]) -> float:
    # efficient & correctness

    # given an array prices: List[float] of length n_prices
    # create an array points of Points, which have price and day attributes (length n_points = n_prices)
    # sort points by price, day ascending
    points = []  # initialize
    for day, price in enumerate(prices):
        point = Point(price=price, day=day)
        points.append(point)
    points.sort()  # sorts by price, day ascending in place

    # debugging
    # [print(point) for point in points[:10]]
    # [print(point) for point in points[-10:]]

    # store the rank of each point
    for rank, point in enumerate(points):
        # rank is also the index of the point in points
        point.rank = rank
    n_points = len(points)

    start, end = points[0], points[n_points - 1]
    pairs = [PointPair(start, end)]  # heapq
    invalid_pairs = set()  # keep track of which pairs we've checked

    # check point pairs by price_delta descending
    while pairs and (pairs[0].price_delta > 0) and (pairs[0].profit is None):
        pair = heappop(pairs)
        invalid_pairs.add(pair)
        #print("invalidated pair: " + str(pair))
        start, end = pair.start, pair.end
        next_left = PointPair(start, points[end.rank - 1])
        next_right = PointPair(points[start.rank + 1], end)
        if next_left not in invalid_pairs:
            heappush(pairs, next_left)
        if next_right not in invalid_pairs:
            heappush(pairs, next_right)

    # debugging
    # N = min(5, len(pairs))
    # print("top {0} pairs in the heapq:\n".format(N))
    # for _ in range(N):
    #     pair = heappop(pairs)
    #     print(pair)

    profit = pairs[0].profit
    if profit is None:
        return 0.0
    else:
        #print("max profit pair: " + str(pairs[0]))
        return profit

# max_profit_in_range(prices, 0, len(prices)-1, 0.0)

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('buy_and_sell_stock.py',
                                       'buy_and_sell_stock.tsv',
                                       buy_and_sell_stock_once))
