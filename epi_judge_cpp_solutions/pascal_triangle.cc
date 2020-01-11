#include <vector>

#include "test_framework/generic_test.h"

using std::vector;

vector<vector<int>> GeneratePascalTriangle(int num_rows) {
  vector<vector<int>> pascal_triangle;
  for (int i = 0; i < num_rows; ++i) {
    vector<int> curr_row;
    for (int j = 0; j <= i; ++j) {
      // Sets this entry to the sum of the two above adjacent entries if they
      // exist.
      curr_row.emplace_back(0 < j && j < i ? pascal_triangle.back()[j - 1] +
                                                 pascal_triangle.back()[j]
                                           : 1);
    }
    pascal_triangle.emplace_back(curr_row);
  }
  return pascal_triangle;
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"num_rows"};
  return GenericTestMain(args, "pascal_triangle.cc", "pascal_triangle.tsv", &GeneratePascalTriangle,
                         DefaultComparator{}, param_names);
}
// clang-format on
