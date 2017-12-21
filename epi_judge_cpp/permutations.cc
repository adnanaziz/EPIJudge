#include <vector>

using std::vector;

vector<vector<int>> Permutations(vector<int> A) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "permutations.tsv", &Permutations,
                    &UnorderedComparator<vector<vector<int>>>);
  return 0;
}
