#include <algorithm>
#include <array>
#include <iterator>
#include <limits>
#include <vector>

#include "test_framework/generic_test.h"

using std::array;
using std::max;
using std::min;
using std::numeric_limits;
using std::size;
using std::vector;

double BuyAndSellStockTwice(const vector<double>& prices) {
  double max_total_profit = 0;
  vector<double> first_buy_sell_profits(size(prices), 0);
  double min_price_so_far = numeric_limits<double>::infinity();

  // Forward phase. For each day, we record maximum profit if we
  // sell on that day.
  for (int i = 0; i < size(prices); ++i) {
    min_price_so_far = min(min_price_so_far, prices[i]);
    max_total_profit = max(max_total_profit, prices[i] - min_price_so_far);
    first_buy_sell_profits[i] = max_total_profit;
  }

  // Backward phase. For each day, find the maximum profit if we make
  // the second buy on that day.
  double max_price_so_far = numeric_limits<double>::min();
  for (int i = size(prices) - 1; i > 0; --i) {
    max_price_so_far = max(max_price_so_far, prices[i]);
    max_total_profit = max(max_total_profit, max_price_so_far - prices[i] +
                                                 first_buy_sell_profits[i]);
  }
  return max_total_profit;
}

double BuyAndSellStockTwiceConstantSpace(const vector<double>& prices) {
  array<double, 2> min_prices = {numeric_limits<double>::infinity(),
                                 numeric_limits<double>::infinity()},
                   max_profits = {0.0, 0.0};
  for (double price : prices) {
    for (int i = 1; i >= 0; --i) {
      max_profits[i] = max(max_profits[i], price - min_prices[i]);
      min_prices[i] =
          min(min_prices[i], price - (i - 1 >= 0 ? max_profits[i - 1] : 0.0));
    }
  }
  return max_profits[1];
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock_twice.cc",
                         "buy_and_sell_stock_twice.tsv", &BuyAndSellStockTwice,
                         DefaultComparator{}, param_names);
}
