#include "test_framework/generic_test.h"
unsigned long long Add(unsigned long long, unsigned long long);

unsigned long long Multiply(unsigned long long x, unsigned long long y) {
  unsigned long long sum = 0;
  while (x) {
    // Examines each bit of x.
    if (x & 1) {
      sum = Add(sum, y);
    }
    x >>= 1, y <<= 1;
  }
  return sum;
}

unsigned long long Add(unsigned long long a, unsigned long long b) {
  return b == 0 ? a : Add(a ^ b, (a & b) << 1);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "primitive_multiply.cc",
                         "primitive_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}
