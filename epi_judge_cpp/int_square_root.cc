
int SquareRoot(int k) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"k"};
  generic_test_main(argc, argv, param_names, "int_square_root.tsv",
                    &SquareRoot);
  return 0;
}
