#include <vector>

using std::vector;

vector<int> Multiply(vector<int> num1, vector<int> num2) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "int_as_array_multiply.tsv", &Multiply);
  return 0;
}
