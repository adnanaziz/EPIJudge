#include <vector>

using std::vector;

// The numbering starts from one, i.e., if A = [3, 1, -1, 2] then
// FindKthLargest(1, A) returns 3, FindKthLargest(2, A) returns 2,
// FindKthLargest(3, A) returns 1, and FindKthLargest(4, A) returns -1.
int FindKthLargest(int k, vector<int>* A_ptr) {
  // Implement this placeholder.
  return 0;
}

int FindKthLargestWrapper(int k, vector<int>& A) {
  return FindKthLargest(k, &A);
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"k", "A"};
  generic_test_main(argc, argv, param_names, "kth_largest_in_array.tsv",
                    &FindKthLargestWrapper);
  return 0;
}
