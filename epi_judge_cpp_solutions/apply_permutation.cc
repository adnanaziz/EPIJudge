#include <algorithm>
#include <vector>

#include "test_framework/generic_test.h"

using std::swap;
using std::vector;

void ApplyPermutation(vector<int> perm, vector<int>* A_ptr) {
  vector<int>& A = *A_ptr;
  for (int i = 0; i < size(A); ++i) {
    while (perm[i] != i) {
      swap(A[i], A[perm[i]]);
      swap(perm[i], perm[perm[i]]);
    }
  }
}

vector<int> ApplyPermutationWrapper(const vector<int>& perm, vector<int> A) {
  ApplyPermutation(perm, &A);
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"perm", "A"};
  return GenericTestMain(args, "apply_permutation.cc", "apply_permutation.tsv",
                         &ApplyPermutationWrapper, DefaultComparator{},
                         param_names);
}
