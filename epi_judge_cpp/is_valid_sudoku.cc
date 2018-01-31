#include <vector>

using std::vector;

// Check if a partially filled matrix has any conflicts.
bool IsValidSudoku(const vector<vector<int>>& partial_assignment) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"partial_assignment"};
  generic_test_main(argc, argv, param_names, "is_valid_sudoku.tsv",
                    &IsValidSudoku);
  return 0;
}
