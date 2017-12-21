#include <vector>

using std::vector;

int MaxSubarraySumInCircular(const vector<int>& A) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "maximum_subarray_in_circular_array.tsv",
                    &MaxSubarraySumInCircular);
  return 0;
}
