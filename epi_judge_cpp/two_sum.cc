#include <vector>

using std::vector;

bool HasTwoSum(const vector<int>& A, int t) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "t"};
  GenericTestMain(args, "two_sum.tsv", &HasTwoSum, DefaultComparator{},
                  param_names);
  return 0;
}
