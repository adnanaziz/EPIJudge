#include <algorithm>
#include <vector>

#include "test_framework/generic_test.h"

using std::max;
using std::max_element;
using std::vector;

int LongestNondecreasingSubsequenceLength(const vector<int>& A) {
  // max_length[i] holds the length of the longest nondecreasing subsequence
  // of A[0, i].
  vector<int> max_length(size(A), 1);
  for (int i = 1; i < size(A); ++i) {
    for (int j = 0; j < i; ++j) {
      if (A[i] >= A[j]) {
        max_length[i] = max(max_length[i], max_length[j] + 1);
      }
    }
  }
  return *max_element(begin(max_length), end(max_length));
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"A"};
  return GenericTestMain(args, "longest_nondecreasing_subsequence.cc", "longest_nondecreasing_subsequence.tsv", &LongestNondecreasingSubsequenceLength,
                         DefaultComparator{}, param_names);
}
// clang-format on
