#include <vector>

using std::vector;

vector<int> KLargestInBinaryHeap(const vector<int>& A, int k) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "k_largest_in_heap.tsv", &KLargestInBinaryHeap,
                    &UnorderedComparator<std::vector<int>>);
  return 0;
}
