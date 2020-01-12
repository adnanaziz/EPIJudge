#include <algorithm>
#include <numeric>
#include <vector>

#include "test_framework/generic_test.h"

using std::min;
using std::vector;

int FindLongestSubarrayLessEqualK(const vector<int>& A, int k) {
  // Builds the prefix sum according to A.
  vector<int> prefix_sum;
  partial_sum(cbegin(A), cend(A), back_inserter(prefix_sum));

  // Early returns if the sum of A is smaller than or equal to k.
  if (prefix_sum.back() <= k) {
    return size(A);
  }

  // Builds min_prefix_sum.
  vector<int> min_prefix_sum = prefix_sum;
  for (int i = size(min_prefix_sum) - 2; i >= 0; --i) {
    min_prefix_sum[i] = min(min_prefix_sum[i], min_prefix_sum[i + 1]);
  }

  int a = 0, b = 0, max_length = 0;
  while (a < size(A) && b < size(A)) {
    if (int min_curr_sum =
            a > 0 ? min_prefix_sum[b] - prefix_sum[a - 1] : min_prefix_sum[b];
        min_curr_sum <= k) {
      int curr_length = b - a + 1;
      if (curr_length > max_length) {
        max_length = curr_length;
      }
      ++b;
    } else {  // min_curr_sum > k.
      ++a;
    }
  }
  return max_length;
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"A", "k"};
  return GenericTestMain(args, "longest_subarray_with_sum_constraint.cc", "longest_subarray_with_sum_constraint.tsv", &FindLongestSubarrayLessEqualK,
                         DefaultComparator{}, param_names);
}
// clang-format on
