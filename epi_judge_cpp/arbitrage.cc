#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

bool IsArbitrageExist(vector<vector<double>> graph) {
  // TODO - you fill in here.
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"graph"};
  return GenericTestMain(args, "arbitrage.cc", "arbitrage.tsv",
                         &IsArbitrageExist, DefaultComparator{}, param_names);
}
