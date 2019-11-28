#include <algorithm>
#include <vector>

#include "test_framework/generic_test.h"

using std::swap;
using std::vector;

void DirectedPermutations(int, vector<int> *, vector<vector<int>> *);

vector<vector<int>> Permutations(vector<int> A) {
  vector<vector<int>> result;
  DirectedPermutations(0, &A, &result);
  return result;
}

void DirectedPermutations(int i, vector<int> *A_ptr,
                          vector<vector<int>> *result) {
  vector<int> &A = *A_ptr;
  if (i == size(A) - 1) {
    result->emplace_back(A);
    return;
  }

  // Try every possibility for A[i].
  for (int j = i; j < size(A); ++j) {
    swap(A[i], A[j]);
    // Generate all permutations for A[i + 1, size(A) - 1].
    DirectedPermutations(i + 1, A_ptr, result);
    swap(A[i], A[j]);
  }
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"A"};
  return GenericTestMain(args, "permutations.cc", "permutations.tsv", &Permutations,
                         UnorderedComparator{}, param_names);
}
// clang-format on
