#include <vector>

using std::vector;

bool IsArbitrageExist(vector<vector<double>> graph) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"graph"};
  GenericTestMain(args, "arbitrage.tsv", &IsArbitrageExist, DefaultComparator{},
                  param_names);
  return 0;
}
