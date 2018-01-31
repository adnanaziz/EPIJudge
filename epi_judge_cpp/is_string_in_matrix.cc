#include <vector>

using std::vector;

bool IsPatternContainedInGrid(const vector<vector<int>>& grid,
                              const vector<int>& pattern) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"grid", "pattern"};
  generic_test_main(argc, argv, param_names, "is_string_in_matrix.tsv",
                    &IsPatternContainedInGrid);
  return 0;
}
