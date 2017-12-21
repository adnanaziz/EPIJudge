#include <vector>

using std::vector;

vector<int> NextPermutation(vector<int> perm) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "next_permutation.tsv", &NextPermutation);
  return 0;
}
