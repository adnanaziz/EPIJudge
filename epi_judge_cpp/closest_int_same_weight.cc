#include "test_framework/generic_test.h"

unsigned long long ClosestIntSameBitCount(unsigned long long x) {
  // Implement this placeholder.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "closest_int_same_weight.tsv",
                         &ClosestIntSameBitCount, DefaultComparator{},
                         param_names);
}
