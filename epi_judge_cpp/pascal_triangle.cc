#include <vector>
#include "test_framework/generic_test.h"

using std::vector;

vector<vector<int>> GeneratePascalTriangle(int num_rows) {
  // Implement this placeholder.
  return {};
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num_rows"};
  return GenericTestMain(args, "pascal_triangle.tsv", &GeneratePascalTriangle,
                         DefaultComparator{}, param_names);
}
