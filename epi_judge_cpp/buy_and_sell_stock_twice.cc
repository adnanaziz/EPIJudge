#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
double BuyAndSellStockTwice(const vector<double>& prices) {
  // TODO - you fill in here.
  return 0.0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock_twice.cc",
                         "buy_and_sell_stock_twice.tsv", &BuyAndSellStockTwice,
                         DefaultComparator{}, param_names);
}
