

unsigned long ReverseBits(unsigned long x) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "reverse_bits.tsv", &ReverseBits);
  return 0;
}
