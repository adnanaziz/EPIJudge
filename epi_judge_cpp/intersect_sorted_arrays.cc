#include <vector>

using std::vector;

vector<int> IntersectTwoSortedArrays(const vector<int>& A,
                                     const vector<int>& B) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  GenericTestMain(args, "intersect_sorted_arrays.tsv",
                  &IntersectTwoSortedArrays, DefaultComparator{}, param_names);
  return 0;
}
