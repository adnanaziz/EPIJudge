#include <vector>

#include "test_framework/generic_test.h"

using std::vector;

struct Subarray {
  int start = 0, end = 0;
};

Subarray FindLongestIncreasingSubarray(const vector<int>& A) {
  int max_length = 1;
  Subarray result;
  int i = 0;
  while (i < size(A) - max_length) {
    // Backward check and skip if A[j - 1] >= A[j].
    bool is_skippable = false;
    for (int j = i + max_length; j > i; --j) {
      if (A[j - 1] >= A[j]) {
        i = j;
        is_skippable = true;
        break;
      }
    }

    // Forward check if it is not skippable.
    if (!is_skippable) {
      i += max_length;
      while (i < size(A) && A[i - 1] < A[i]) {
        ++i, ++max_length;
      }
      result = {i - max_length, i - 1};
    }
  }
  return result;
}

int FindLongestIncreasingSubarrayWrapper(const vector<int>& A) {
  Subarray result = FindLongestIncreasingSubarray(A);
  return result.end - result.start + 1;
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"A"};
  return GenericTestMain(args, "longest_increasing_subarray.cc", "longest_increasing_subarray.tsv", &FindLongestIncreasingSubarrayWrapper,
                         DefaultComparator{}, param_names);
}
// clang-format on
