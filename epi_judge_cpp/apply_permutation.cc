#include <vector>

using std::vector;

void ApplyPermutation(vector<int>* perm_ptr, vector<int>* A_ptr) {
  // Implement this placeholder.
  return;
}

vector<int> ApplyPermutationWrapper(vector<int> perm, vector<int> A) {
  ApplyPermutation(&perm, &A);
  return A;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"perm", "A"};
  GenericTestMain(args, "apply_permutation.tsv", &ApplyPermutationWrapper,
                  DefaultComparator{}, param_names);
  return 0;
}
