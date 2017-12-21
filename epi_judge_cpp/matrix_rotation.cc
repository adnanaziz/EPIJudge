#include <vector>

using std::vector;

void RotateMatrix(vector<vector<int>>* square_matrix_ptr) {
  // Implement this placeholder.
  return;
}

vector<vector<int>> RotateMatrixWrapper(vector<vector<int>> m) {
  RotateMatrix(&m);
  return m;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "matrix_rotation.tsv", &RotateMatrixWrapper);
  return 0;
}
