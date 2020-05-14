#include <algorithm>
#include <vector>

#include "test_framework/generic_test.h"

using std::vector;

void RotateMatrix(vector<vector<int>>* square_matrix_ptr) {
  vector<vector<int>>& square_matrix = *square_matrix_ptr;
  const int matrix_size = size(square_matrix) - 1;
  for (int i = 0; i < (size(square_matrix) / 2); ++i) {
    for (int j = i; j < matrix_size - i; ++j) {
      // Perform a 4-way exchange.
      int temp1 = square_matrix[matrix_size - j][i];
      int temp2 = square_matrix[matrix_size - i][matrix_size - j];
      int temp3 = square_matrix[j][matrix_size - i];
      int temp4 = square_matrix[i][j];
      square_matrix[i][j] = temp1;
      square_matrix[matrix_size - j][i] = temp2;
      square_matrix[matrix_size - i][matrix_size - j] = temp3;
      square_matrix[j][matrix_size - i] = temp4;
    }
  }
}

vector<vector<int>> RotateMatrixWrapper(vector<vector<int>> square_matrix) {
  RotateMatrix(&square_matrix);
  return square_matrix;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"square_matrix"};
  return GenericTestMain(args, "matrix_rotation.cc", "matrix_rotation.tsv",
                         &RotateMatrixWrapper, DefaultComparator{},
                         param_names);
}
