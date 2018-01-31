#include <vector>

using std::vector;

double BuyAndSellStockKTimes(const vector<double>& prices, int k) {
  // Implement this placeholder.
  return 0.0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"&prices", "k"};
  generic_test_main(argc, argv, param_names, "buy_and_sell_stock_k_times.tsv",
                    &BuyAndSellStockKTimes);
  return 0;
}
