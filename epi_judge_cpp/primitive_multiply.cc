#include "test_framework/generic_test.h"

unsigned long long Multiply(unsigned long long x, unsigned long long y) {
  // Implement this placeholder.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "primitive_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}
