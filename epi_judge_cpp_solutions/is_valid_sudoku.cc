#include <cmath>
#include <deque>
#include <vector>

#include "test_framework/generic_test.h"

using std::deque;
using std::vector;

bool HasDuplicate(const vector<vector<int>>&, int, int, int, int);

// Check if a partially filled matrix has any conflicts.
bool IsValidSudoku(const vector<vector<int>>& partial_assignment) {
  // Check row constraints.
  for (int i = 0; i < size(partial_assignment); ++i) {
    if (HasDuplicate(partial_assignment, i, i + 1, 0,
                     size(partial_assignment))) {
      return false;
    }
  }

  // Check column constraints.
  for (int j = 0; j < size(partial_assignment); ++j) {
    if (HasDuplicate(partial_assignment, 0, size(partial_assignment), j,
                     j + 1)) {
      return false;
    }
  }

  // Check region constraints.
  int region_size = sqrt(size(partial_assignment));
  for (int I = 0; I < region_size; ++I) {
    for (int J = 0; J < region_size; ++J) {
      if (HasDuplicate(partial_assignment, region_size * I,
                       region_size * (I + 1), region_size * J,
                       region_size * (J + 1))) {
        return false;
      }
    }
  }
  return true;
}

// Return true if subarray partial_assignment[start_row, end_row -
// 1][start_col, end_col - 1] contains any duplicates in {1, 2, ...,
// size(partial_assignment)}; otherwise return false.
bool HasDuplicate(const vector<vector<int>>& partial_assignment, int start_row,
                  int end_row, int start_col, int end_col) {
  deque<bool> is_present(size(partial_assignment) + 1, false);
  for (int i = start_row; i < end_row; ++i) {
    for (int j = start_col; j < end_col; ++j) {
      if (partial_assignment[i][j] != 0 &&
          is_present[partial_assignment[i][j]]) {
        return true;
      }
      is_present[partial_assignment[i][j]] = true;
    }
  }
  return false;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"partial_assignment"};
  return GenericTestMain(args, "is_valid_sudoku.cc", "is_valid_sudoku.tsv",
                         &IsValidSudoku, DefaultComparator{}, param_names);
}
