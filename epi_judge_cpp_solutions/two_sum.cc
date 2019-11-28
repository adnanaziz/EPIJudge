#include <iterator>
#include <vector>

#include "test_framework/generic_test.h"

using std::size;
using std::vector;

bool HasTwoSum(const vector<int>& A, int t) {
  int i = 0, j = size(A) - 1;
  while (i <= j) {
    if (A[i] + A[j] == t) {
      return true;
    } else if (A[i] + A[j] < t) {
      ++i;
    } else {  // A[i] + A[j] > t.
      --j;
    }
  }
  return false;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "t"};
  return GenericTestMain(args, "two_sum.cc", "two_sum.tsv", &HasTwoSum,
                         DefaultComparator{}, param_names);
}
