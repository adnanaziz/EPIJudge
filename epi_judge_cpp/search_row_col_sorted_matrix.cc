#include <vector>

using std::vector;

bool MatrixSearch(const vector<vector<int>>& A, int x) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "x"};
  GenericTestMain(args, "search_row_col_sorted_matrix.tsv", &MatrixSearch,
                  DefaultComparator{}, param_names);
  return 0;
}
