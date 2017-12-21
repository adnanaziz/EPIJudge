#include <vector>

using std::vector;

int FindLongestSubarrayLessEqualK(const vector<int>& A, int k) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "longest_subarray_with_sum_constraint.tsv",
                    &FindLongestSubarrayLessEqualK);
  return 0;
}
