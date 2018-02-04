#include <vector>

using std::vector;

int MaximumRevenue(const vector<int>& coins) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"coins"};
  GenericTestMain(args, "picking_up_coins.tsv", &MaximumRevenue,
                  DefaultComparator{}, param_names);
  return 0;
}
