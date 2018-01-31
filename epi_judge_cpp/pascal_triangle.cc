#include <vector>

using std::vector;

vector<vector<int>> GeneratePascalTriangle(int num_rows) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"num_rows"};
  generic_test_main(argc, argv, param_names, "pascal_triangle.tsv",
                    &GeneratePascalTriangle);
  return 0;
}
