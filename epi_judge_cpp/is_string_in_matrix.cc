#include <vector>

using std::vector;

bool IsPatternContainedInGrid(const vector<vector<int>>& grid,
                              const vector<int>& pattern) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"grid", "pattern"};
  GenericTestMain(args, "is_string_in_matrix.tsv", &IsPatternContainedInGrid,
                  DefaultComparator{}, param_names);
  return 0;
}
