#include <vector>

using std::vector;

vector<int> KLargestInBinaryHeap(const vector<int>& A, int k) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "k"};
  GenericTestMain(args, "k_largest_in_heap.tsv", &KLargestInBinaryHeap,
                  &UnorderedComparator<std::vector<int>>, param_names);
  return 0;
}
