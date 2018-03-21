#include "test_framework/generic_test.h"
double Power(double x, int y) {
  // Implement this placeholder.
  return 0.0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "power_x_y.tsv", &Power, DefaultComparator{},
                         param_names);
}
