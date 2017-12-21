#include <algorithm>
#include <iterator>
#include <vector>

using std::vector;

vector<vector<int>> NQueens(int n) {
  // Implement this placeholder.
  return {};
}

bool Comp(vector<vector<int>>& a, vector<vector<int>>& b) {
  std::sort(std::begin(a), std::end(a));
  std::sort(std::begin(b), std::end(b));
  return a == b;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "n_queens.tsv", &NQueens, &Comp);
  return 0;
}
