#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

int FindLongestSubarrayLessEqualK(const vector<int>& A, int k) {
  // TODO - you fill in here.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "k"};
  return GenericTestMain(args, "longest_subarray_with_sum_constraint.cc",
                         "longest_subarray_with_sum_constraint.tsv",
                         &FindLongestSubarrayLessEqualK, DefaultComparator{},
                         param_names);
}
