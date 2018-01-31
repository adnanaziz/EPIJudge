#include <vector>

using std::vector;

int FindClosestElementsInSortedArrays(
    const vector<vector<int>>& sorted_arrays) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"sorted_arrays"};
  generic_test_main(argc, argv, param_names,
                    "minimum_distance_3_sorted_arrays.tsv",
                    &FindClosestElementsInSortedArrays);
  return 0;
}
