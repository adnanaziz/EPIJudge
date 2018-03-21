#include "test_framework/generic_test.h"

int SquareRoot(int k) {
  // Implement this placeholder.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"k"};
  return GenericTestMain(args, "int_square_root.tsv", &SquareRoot,
                         DefaultComparator{}, param_names);
}
