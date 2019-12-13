#include <algorithm>
#include <vector>

#include "test_framework/generic_test.h"

using std::max;
using std::vector;

int FindMaximumSubarray(const vector<int>& A) {
  int max_seen = 0, max_end = 0;
  for (int a : A) {
    max_end = max(a, a + max_end);
    max_seen = max(max_seen, max_end);
  }
  return max_seen;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "max_sum_subarray.cc", "max_sum_subarray.tsv",
                         &FindMaximumSubarray, DefaultComparator{},
                         param_names);
}
