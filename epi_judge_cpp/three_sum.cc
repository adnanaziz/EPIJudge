#include <vector>
#include "test_framework/generic_test.h"

using std::vector;

bool HasThreeSum(vector<int> A, int t) {
  // Implement this placeholder.
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "t"};
  return GenericTestMain(args, "three_sum.tsv", &HasThreeSum,
                         DefaultComparator{}, param_names);
}
