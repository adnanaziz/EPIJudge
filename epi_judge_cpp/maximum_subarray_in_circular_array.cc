#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

int MaxSubarraySumInCircular(const vector<int>& A) {
  // TODO - you fill in here.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "maximum_subarray_in_circular_array.cc",
                         "maximum_subarray_in_circular_array.tsv",
                         &MaxSubarraySumInCircular, DefaultComparator{},
                         param_names);
}
