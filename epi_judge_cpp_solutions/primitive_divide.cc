#include "test_framework/generic_test.h"

int Divide(int x, int y) {
  int result = 0;
  int power = 32;
  unsigned long long y_power = static_cast<unsigned long long>(y) << power;
  while (x >= y) {
    while (y_power > x) {
      y_power >>= 1;
      --power;
    }

    result += 1 << power;
    x -= y_power;
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "primitive_divide.cc", "primitive_divide.tsv",
                         &Divide, DefaultComparator{}, param_names);
}
