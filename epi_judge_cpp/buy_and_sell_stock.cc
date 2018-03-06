#include <vector>

using std::vector;

double BuyAndSellStockOnce(const vector<double>& prices) {
  // Implement this placeholder.
  return 0.0;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, timeout_seconds, "buy_and_sell_stock.tsv",
                         &BuyAndSellStockOnce, DefaultComparator{},
                         param_names);
}
