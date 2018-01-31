#include <vector>

using std::vector;

vector<int> IntersectTwoSortedArrays(const vector<int>& A,
                                     const vector<int>& B) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"A", "B"};
  generic_test_main(argc, argv, param_names, "intersect_sorted_arrays.tsv",
                    &IntersectTwoSortedArrays);
  return 0;
}
