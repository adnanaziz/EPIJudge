#include <vector>

using std::vector;

vector<int> NextPermutation(vector<int> perm) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"perm"};
  generic_test_main(argc, argv, param_names, "next_permutation.tsv",
                    &NextPermutation);
  return 0;
}
