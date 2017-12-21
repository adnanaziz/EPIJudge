#include <vector>

using std::vector;

// The numbering starts from one, i.e., if A = [3, 1, -1, 2] then
// FindKthLargest(1, A) returns 3, FindKthLargest(2, A) returns 2,
// FindKthLargest(3, A) returns 1, and FindKthLargest(4, A) returns -1.
int FindKthLargest(int k, vector<int>* A_ptr) {
  // Implement this placeholder.
  return 0;
}

int FindKthLargestWrapper(int k, vector<int>& v) {
  return FindKthLargest(k, &v);
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "kth_largest_in_array.tsv",
                    &FindKthLargestWrapper);
  return 0;
}
