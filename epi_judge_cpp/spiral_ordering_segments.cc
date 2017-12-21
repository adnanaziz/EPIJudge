#include <vector>

using std::vector;

vector<int> MatrixInSpiralOrder(vector<vector<int>> square_matrix) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "spiral_ordering_segments.tsv",
                    &MatrixInSpiralOrder);
  return 0;
}
