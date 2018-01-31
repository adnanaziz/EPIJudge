
unsigned long Multiply(unsigned long x, unsigned long y) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"x", "y"};
  generic_test_main(argc, argv, param_names, "primitive_multiply.tsv",
                    &Multiply);
  return 0;
}
