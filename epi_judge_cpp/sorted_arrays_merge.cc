#include <vector>

using std::vector;

vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sorted_arrays"};
  GenericTestMain(args, "sorted_arrays_merge.tsv", &MergeSortedArrays,
                  DefaultComparator{}, param_names);
  return 0;
}
