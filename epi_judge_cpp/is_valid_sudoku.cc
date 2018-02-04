#include <vector>

using std::vector;

// Check if a partially filled matrix has any conflicts.
bool IsValidSudoku(const vector<vector<int>>& partial_assignment) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"partial_assignment"};
  GenericTestMain(args, "is_valid_sudoku.tsv", &IsValidSudoku,
                  DefaultComparator{}, param_names);
  return 0;
}
