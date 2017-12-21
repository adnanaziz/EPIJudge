#include <vector>

using std::vector;

int FindClosestElementsInSortedArrays(
    const vector<vector<int>>& sorted_arrays) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "minimum_distance_3_sorted_arrays.tsv",
                    &FindClosestElementsInSortedArrays);
  return 0;
}
