

int NumberOfWaysToTop(int top, int maximum_step) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"top", "maximum_step"};
  generic_test_main(argc, argv, param_names,
                    "number_of_traversals_staircase.tsv", &NumberOfWaysToTop);
  return 0;
}
