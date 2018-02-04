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

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  GenericTestMain(args, "n_queens.tsv", &NQueens, &Comp, param_names);
  return 0;
}
