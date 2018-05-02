#include <algorithm>
#include <vector>
#include "test_framework/generic_test.h"

using std::swap;
using std::vector;

void ApplyPermutation(vector<int>* perm_ptr, vector<int>* A_ptr) {
  vector<int>&perm = *perm_ptr, &A = *A_ptr;
  for (int i = 0; i < size(A); ++i) {
    // Check if the element at index i has not been moved by checking if
    // perm[i] is nonnegative.
    int next = i;
    while (perm[next] >= 0) {
      swap(A[i], A[perm[next]]);
      int temp = perm[next];
      // Subtracts size(perm) from an entry in perm to make it negative,
      // which indicates the corresponding move has been performed.
      perm[next] -= size(perm);
      next = temp;
    }
  }

  // Restore perm.
  for_each(begin(perm), end(perm), [&perm](int& x) { x += size(perm); });
}

vector<int> ApplyPermutationWrapper(vector<int> perm, vector<int> A) {
  ApplyPermutation(&perm, &A);
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"perm", "A"};
  return GenericTestMain(args, "apply_permutation.cc", "apply_permutation.tsv",
                         &ApplyPermutationWrapper, DefaultComparator{},
                         param_names);
}
