#include <vector>

using std::vector;

vector<vector<int>> GeneratePascalTriangle(int num_rows) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num_rows"};
  GenericTestMain(args, "pascal_triangle.tsv", &GeneratePascalTriangle,
                  DefaultComparator{}, param_names);
  return 0;
}
