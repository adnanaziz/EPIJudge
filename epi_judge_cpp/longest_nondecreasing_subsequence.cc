#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

int LongestNondecreasingSubsequenceLength(const vector<int>& A) {
    vector<int> longest_len(A.size(), 1);

    for (int i = 1; i < A.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] <= A[i]) {
                longest_len[i] = std::max(longest_len[i], 1 + longest_len[j]);
            }
        }
    
    }

    return *std::max_element(longest_len.begin(), longest_len.end());
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "longest_nondecreasing_subsequence.cc",
                         "longest_nondecreasing_subsequence.tsv",
                         &LongestNondecreasingSubsequenceLength,
                         DefaultComparator{}, param_names);
}
