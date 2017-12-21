#include <vector>

using std::vector;

int FindKthInTwoSortedArrays(const vector<int>& A, const vector<int>& B,
                             int k) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "kth_largest_element_in_two_sorted_arrays.tsv",
                    &FindKthInTwoSortedArrays);
  return 0;
}
