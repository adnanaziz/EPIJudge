

int NumberOfWays(int n, int m) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"n", "m"};
  generic_test_main(argc, argv, param_names, "number_of_traversals_matrix.tsv",
                    &NumberOfWays);
  return 0;
}
