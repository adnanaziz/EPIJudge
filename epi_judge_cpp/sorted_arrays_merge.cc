#include <vector>

using std::vector;

vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"sorted_arrays"};
  generic_test_main(argc, argv, param_names, "sorted_arrays_merge.tsv",
                    &MergeSortedArrays);
  return 0;
}
