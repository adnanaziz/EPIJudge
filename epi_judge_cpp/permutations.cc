#include <vector>

using std::vector;

vector<vector<int>> Permutations(vector<int> A) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"A"};
  generic_test_main(argc, argv, param_names, "permutations.tsv", &Permutations,
                    &UnorderedComparator<vector<vector<int>>>);
  return 0;
}
