#include <vector>

using std::vector;

void RotateMatrix(vector<vector<int>>* square_matrix_ptr) {
  // Implement this placeholder.
  return;
}

vector<vector<int>> RotateMatrixWrapper(vector<vector<int>> square_matrix) {
  RotateMatrix(&square_matrix);
  return square_matrix;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"square_matrix"};
  generic_test_main(argc, argv, param_names, "matrix_rotation.tsv",
                    &RotateMatrixWrapper);
  return 0;
}
