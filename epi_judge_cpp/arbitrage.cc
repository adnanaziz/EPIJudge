#include <vector>

using std::vector;

bool IsArbitrageExist(vector<vector<double>> G) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "arbitrage.tsv", &IsArbitrageExist);
  return 0;
}
