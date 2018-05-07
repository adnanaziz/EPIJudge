#include <algorithm>
#include <iterator>
#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

vector<vector<int>> NQueens(int n) {
  // TODO - you fill in here.
  return {};
}
bool Comp(vector<vector<int>>& a, vector<vector<int>>& b) {
  std::sort(std::begin(a), std::end(a));
  std::sort(std::begin(b), std::end(b));
  return a == b;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "n_queens.cc", "n_queens.tsv", &NQueens, &Comp,
                         param_names);
}
