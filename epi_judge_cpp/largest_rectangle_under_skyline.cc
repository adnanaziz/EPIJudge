#include <vector>

using std::vector;

int CalculateLargestRectangle(const vector<int>& heights) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "largest_rectangle_under_skyline.tsv",
                    &CalculateLargestRectangle);
  return 0;
}
