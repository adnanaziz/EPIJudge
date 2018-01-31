#include <vector>

using std::vector;

vector<vector<int>> Combinations(int n, int k) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"int",          "int", "int",
                                       "vector<int>*", "n",   "k"};
  generic_test_main(argc, argv, param_names, "combinations.tsv", &Combinations,
                    &UnorderedComparator<std::vector<std::vector<int>>>);
  return 0;
}
