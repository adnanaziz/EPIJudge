#include <vector>

using std::vector;

bool HasTwoSum(const vector<int>& A, int t) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"A", "t"};
  generic_test_main(argc, argv, param_names, "two_sum.tsv", &HasTwoSum);
  return 0;
}
