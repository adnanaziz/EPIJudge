#include <cstdlib>

#include "test_framework/generic_test.h"

long long Reverse(int x) {
  long long result = 0;
  while (x) {
    // If x is an negative, x % 10 is the negative of least significant digit.
    // For example, -256 % 10 = -6.
    result = result * 10 + x % 10;
    x /= 10;
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "reverse_digits.cc", "reverse_digits.tsv",
                         &Reverse, DefaultComparator{}, param_names);
}
