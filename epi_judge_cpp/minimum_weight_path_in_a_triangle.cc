#include <vector>

using std::vector;

int MinimumPathWeight(const vector<vector<int>>& triangle) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"triangle"};
  GenericTestMain(args, "minimum_weight_path_in_a_triangle.tsv",
                  &MinimumPathWeight, DefaultComparator{}, param_names);
  return 0;
}
