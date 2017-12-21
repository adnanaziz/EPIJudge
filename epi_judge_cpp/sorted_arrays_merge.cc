#include <vector>

using std::vector;

vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "sorted_arrays_merge.tsv", &MergeSortedArrays);
  return 0;
}
