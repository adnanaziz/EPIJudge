

double SquareRoot(double x) {
  // Implement this placeholder.
  return 0.0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "real_square_root.tsv", &SquareRoot);
  return 0;
}
