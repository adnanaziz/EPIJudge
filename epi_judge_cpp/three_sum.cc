#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

bool HasThreeSum(vector<int> A, int t) {
  // TODO - you fill in here.
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "t"};
  return GenericTestMain(args, "three_sum.cc", "three_sum.tsv", &HasThreeSum,
                         DefaultComparator{}, param_names);
}
