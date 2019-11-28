#include <algorithm>
#include <limits>
#include <vector>

#include "test_framework/generic_test.h"

using std::max;
using std::min;
using std::numeric_limits;
using std::vector;

double BuyAndSellStockOnce(const vector<double>& prices) {
  double min_price_so_far = numeric_limits<double>::infinity(), max_profit = 0;
  for (double price : prices) {
    double max_profit_sell_today = price - min_price_so_far;
    max_profit = max(max_profit, max_profit_sell_today);
    min_price_so_far = min(min_price_so_far, price);
  }
  return max_profit;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
