#include <vector>

using std::vector;

double BuyAndSellStockOnce(const vector<double>& prices) {
  // Implement this placeholder.
  return 0.0;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  GenericTestMain(args, "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                  DefaultComparator{}, param_names);
  return 0;
}
