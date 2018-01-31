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

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"perm", "A"};
  generic_test_main(argc, argv, param_names, "apply_permutation.tsv",
                    &ApplyPermutationWrapper);
  return 0;
}
