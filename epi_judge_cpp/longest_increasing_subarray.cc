#include <vector>
#include "test_framework/generic_test.h"

using std::vector;

struct Subarray {
  int start = 0, end = 0;
};

Subarray FindLongestIncreasingSubarray(const vector<int>& A) {
  // Implement this placeholder.
  return {};
}

int FindLongestIncreasingSubarrayWrapper(const vector<int>& A) {
  Subarray result = FindLongestIncreasingSubarray(A);
  return result.end - result.start + 1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "longest_increasing_subarray.tsv",
                         &FindLongestIncreasingSubarrayWrapper,
                         DefaultComparator{}, param_names);
}
