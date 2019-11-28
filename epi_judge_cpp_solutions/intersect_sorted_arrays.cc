#include <algorithm>
#include <vector>

#include "test_framework/generic_test.h"

using std::vector;

vector<int> IntersectTwoSortedArrays(const vector<int>& A,
                                     const vector<int>& B) {
  vector<int> insersection_A_B;
  for (int i = 0; i < size(A); ++i) {
    if ((!i || A[i] != A[i - 1]) && find(begin(B), end(B), A[i]) != end(B)) {
      insersection_A_B.emplace_back(A[i]);
    }
  }
  return insersection_A_B;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(
      args, "intersect_sorted_arrays.cc", "intersect_sorted_arrays.tsv",
      &IntersectTwoSortedArrays, DefaultComparator{}, param_names);
}
