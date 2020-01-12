#include <vector>

#include "test_framework/generic_test.h"

using std::vector;

bool MatrixSearch(const vector<vector<int>>& A, int x) {
  int row = 0, col = size(A[0]) - 1;  // Start from the top-right corner.
  // Keeps searching while there are unclassified rows and columns.
  while (row < size(A) && col >= 0) {
    if (A[row][col] == x) {
      return true;
    } else if (A[row][col] < x) {
      ++row;  // Eliminate this row.
    } else {  // A[row][col] > x.
      --col;  // Eliminate this column.
    }
  }
  return false;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "x"};
  return GenericTestMain(args, "search_row_col_sorted_matrix.cc",
                         "search_row_col_sorted_matrix.tsv", &MatrixSearch,
                         DefaultComparator{}, param_names);
}
