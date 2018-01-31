#include <vector>

using std::vector;

vector<int> KLargestInBinaryHeap(const vector<int>& A, int k) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"A", "k"};
  generic_test_main(argc, argv, param_names, "k_largest_in_heap.tsv",
                    &KLargestInBinaryHeap,
                    &UnorderedComparator<std::vector<int>>);
  return 0;
}
