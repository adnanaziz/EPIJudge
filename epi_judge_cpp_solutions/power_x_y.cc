#include "test_framework/generic_test.h"

double Power(double x, int y) {
  double result = 1.0;
  long long power = y;
  if (y < 0) {
    power = -power, x = 1.0 / x;
  }
  while (power) {
    if (power & 1) {
      result *= x;
    }
    x *= x, power >>= 1;
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "power_x_y.cc", "power_x_y.tsv", &Power,
                         DefaultComparator{}, param_names);
}
