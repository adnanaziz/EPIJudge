#include "test_framework/generic_test.h"
#include <vector>
using std::vector;

int ComputeXChooseY(int x, int y, vector<vector<int>>& x_choose_y) {

    if (y == 0 || x == y)
        return 1;

    if (x_choose_y[x][y] == 0) {
        
        int val_without_y = ComputeXChooseY(x - 1, y, x_choose_y);
        int val_with_y = ComputeXChooseY(x - 1, y - 1, x_choose_y);
        
        x_choose_y[x][y] = val_without_y + val_with_y;
    }
    return x_choose_y[x][y];
}

int ComputeBinomialCoefficient(int n, int k) {
    vector<vector<int>> x_choose_y(n + 1, vector<int>(k+1, 0));
    return ComputeXChooseY(n, k, x_choose_y);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n", "k"};
  return GenericTestMain(
      args, "binomial_coefficients.cc", "binomial_coefficients.tsv",
      &ComputeBinomialCoefficient, DefaultComparator{}, param_names);
}
