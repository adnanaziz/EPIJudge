#include "test_framework/generic_test.h"

long long SwapBits(long long x, int i, int j) {
  // Extract the i-th and j-th bits, and see if they differ.
  if (((x >> i) & 1) != ((x >> j) & 1)) {
    // i-th and j-th bits differ. We will swap them by flipping their values.
    // Select the bits to flip with bit_mask. Since x^1 = 0 when x = 1 and 1
    // when x = 0, we can perform the flip XOR.
    unsigned long long bit_mask = (1ULL << i) | (1ULL << j);
    x ^= bit_mask;
  }
  return x;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "i", "j"};
  return GenericTestMain(args, "swap_bits.cc", "swap_bits.tsv", &SwapBits,
                         DefaultComparator{}, param_names);
}
