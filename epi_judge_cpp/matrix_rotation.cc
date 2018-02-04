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

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"square_matrix"};
  GenericTestMain(args, "matrix_rotation.tsv", &RotateMatrixWrapper,
                  DefaultComparator{}, param_names);
  return 0;
}
