#include <vector>

using std::vector;

vector<int> SortApproximatelySortedData(
    vector<int>::const_iterator sequence_begin,
    const vector<int>::const_iterator& sequence_end, int k) {
  // Implement this placeholder.
  return {};
}

vector<int> SortApproximatelySortedDataWrapper(const vector<int>& sequence,
                                               int k) {
  return SortApproximatelySortedData(cbegin(sequence), cend(sequence), k);
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"sequence", "k"};
  generic_test_main(argc, argv, param_names, "sort_almost_sorted_array.tsv",
                    &SortApproximatelySortedDataWrapper);
  return 0;
}
