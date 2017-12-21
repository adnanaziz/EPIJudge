
unsigned int Multiply(unsigned int x, unsigned int y) {
  // Implement this placeholder.
  return 0;
}

long MultiplyWrapper(long x, long y) {
  return Multiply(static_cast<unsigned int>(x), static_cast<unsigned int>(y));
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "primitive_multiply.tsv", &MultiplyWrapper);
  return 0;
}
