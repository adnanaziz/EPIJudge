#include "test_framework/generic_test.h"

unsigned long long ReverseBits(unsigned long long x) {
  // Implement this placeholder.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "reverse_bits.tsv", &ReverseBits,
                         DefaultComparator{}, param_names);
}
