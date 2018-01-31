long SwapBits(long x, int i, int j) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"x", "i", "j"};
  generic_test_main(argc, argv, param_names, "swap_bits.tsv", &SwapBits);
  return 0;
}
