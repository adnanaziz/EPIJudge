#include <vector>

using std::vector;

struct Subarray {
  int start = 0, end = 0;
};

Subarray FindLongestIncreasingSubarray(const vector<int>& A) {
  // Implement this placeholder.
  return {0, 0};
}

int FindLongestIncreasingSubarrayWrapper(const vector<int>& A) {
  auto result = FindLongestIncreasingSubarray(A);
  return result.end - result.start + 1;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "longest_increasing_subarray.tsv",
                    &FindLongestIncreasingSubarrayWrapper);
  return 0;
}
