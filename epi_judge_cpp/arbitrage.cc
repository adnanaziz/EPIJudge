#include <vector>

using std::vector;

bool IsArbitrageExist(vector<vector<double>> graph) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"graph"};
  generic_test_main(argc, argv, param_names, "arbitrage.tsv",
                    &IsArbitrageExist);
  return 0;
}
