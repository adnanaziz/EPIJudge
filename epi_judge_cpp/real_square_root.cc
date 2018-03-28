#include "test_framework/generic_test.h"

double SquareRoot(double x) {
  // Implement this placeholder.
  return 0.0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "real_square_root.tsv", &SquareRoot,
                         DefaultComparator{}, param_names);
}
