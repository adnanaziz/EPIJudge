#include <vector>

#include "test_framework/generic_test.h"

using std::vector;

void MergeTwoSortedArrays(vector<int>& A, int m, const vector<int>& B, int n) {
  int a = m - 1, b = n - 1, write_idx = m + n - 1;
  while (a >= 0 && b >= 0) {
    A[write_idx--] = A[a] > B[b] ? A[a--] : B[b--];
  }
  while (b >= 0) {
    A[write_idx--] = B[b--];
  }
}

vector<int> MergeTwoSortedArraysWrapper(vector<int> A, int m,
                                        const vector<int>& B, int n) {
  MergeTwoSortedArrays(A, m, B, n);
  return A;
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"A", "m", "B", "n"};
  return GenericTestMain(args, "two_sorted_arrays_merge.cc", "two_sorted_arrays_merge.tsv", &MergeTwoSortedArraysWrapper,
                         DefaultComparator{}, param_names);
}
// clang-format on
