#include <algorithm>
#include <limits>
#include <vector>

#include "test_framework/generic_test.h"

using std::max;
using std::min;
using std::numeric_limits;
using std::vector;

double UnlimitedPairsProfits(const vector<double> &);

double BuyAndSellStockKTimes(const vector<double> &prices, int k) {
  if (k == 0) {
    return 0.0;
  } else if (2 * k >= size(prices)) {
    return UnlimitedPairsProfits(prices);
  }
  vector<double> min_prices(k, numeric_limits<double>::infinity()),
      max_profits(k, 0.0);
  for (double price : prices) {
    for (int i = k - 1; i >= 0; --i) {
      max_profits[i] = max(max_profits[i], price - min_prices[i]);
      min_prices[i] =
          min(min_prices[i], price - (i ? max_profits[i - 1] : 0.0));
    }
  }
  return max_profits.back();
}

double UnlimitedPairsProfits(const vector<double> &prices) {
  double profit = 0.0;
  for (int i = 1; i < size(prices); ++i) {
    profit += max(0.0, prices[i] - prices[i - 1]);
  }
  return profit;
}

int main(int argc, char *argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices", "k"};
  return GenericTestMain(
      args, "buy_and_sell_stock_k_times.cc", "buy_and_sell_stock_k_times.tsv",
      &BuyAndSellStockKTimes, DefaultComparator{}, param_names);
}
