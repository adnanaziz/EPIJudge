#include <vector>

using std::vector;

int FindLongestSubarrayLessEqualK(const vector<int>& A, int k) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "k"};
  GenericTestMain(args, "longest_subarray_with_sum_constraint.tsv",
                  &FindLongestSubarrayLessEqualK, DefaultComparator{},
                  param_names);
  return 0;
}
