#include <vector>

using std::vector;

bool HasTwoSum(const vector<int>& A, int t) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "two_sum.tsv", &HasTwoSum);
  return 0;
}
