#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

double BuyAndSellStockKTimes(const vector<double>& prices, int k) {
  // TODO - you fill in here.
  return 0.0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices", "k"};
  return GenericTestMain(
      args, "buy_and_sell_stock_k_times.cc", "buy_and_sell_stock_k_times.tsv",
      &BuyAndSellStockKTimes, DefaultComparator{}, param_names);
}
