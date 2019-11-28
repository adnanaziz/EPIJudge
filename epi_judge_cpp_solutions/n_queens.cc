#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <memory>
#include <vector>

#include "test_framework/generic_test.h"

using std::make_unique;
using std::vector;

void SolveNQueens(int, int, vector<int>*, vector<vector<int>>*);
bool IsValid(const vector<int>&);

vector<vector<int>> NQueens(int n) {
  vector<vector<int>> result;
  SolveNQueens(n, 0, make_unique<vector<int>>().get(), &result);
  return result;
}

void SolveNQueens(int n, int row, vector<int>* col_placement,
                  vector<vector<int>>* result) {
  if (row == n) {
    // All queens are legally placed.
    result->emplace_back(*col_placement);
  } else {
    for (int col = 0; col < n; ++col) {
      col_placement->emplace_back(col);
      if (IsValid(*col_placement)) {
        SolveNQueens(n, row + 1, col_placement, result);
      }
      col_placement->pop_back();
    }
  }
}

// Test if a newly placed queen will conflict any earlier queens
// placed before.
bool IsValid(const vector<int>& col_placement) {
  int row_id = size(col_placement) - 1;
  for (int i = 0; i < row_id; ++i) {
    if (int diff = abs(col_placement[i] - col_placement[row_id]);
        diff == 0 || diff == row_id - i) {
      // A column or diagonal constraint is violated.
      return false;
    }
  }
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "n_queens.cc", "n_queens.tsv", &NQueens,
                         UnorderedComparator{}, param_names);
}
