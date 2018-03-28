#include <vector>
#include "test_framework/generic_test.h"

using std::vector;

int FindKthInTwoSortedArrays(const vector<int>& A, const vector<int>& B,
                             int k) {
  // Implement this placeholder.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B", "k"};
  return GenericTestMain(args, "kth_largest_element_in_two_sorted_arrays.tsv",
                         &FindKthInTwoSortedArrays, DefaultComparator{},
                         param_names);
}
