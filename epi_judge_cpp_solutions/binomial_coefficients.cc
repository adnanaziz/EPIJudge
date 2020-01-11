#include <memory>
#include <vector>

#include "test_framework/generic_test.h"

using std::make_unique;
using std::min;
using std::vector;

int ComputeXChooseY(int, int, vector<vector<int>>*);

int ComputeBinomialCoefficient(int n, int k) {
  return ComputeXChooseY(
      n, k,
      make_unique<vector<vector<int>>>(n + 1, vector<int>(k + 1, 0)).get());
}

int ComputeXChooseY(int x, int y, vector<vector<int>>* x_choose_y_ptr) {
  if (y == 0 || x == y) {
    return 1;
  }

  vector<vector<int>>& x_choose_y = *x_choose_y_ptr;
  if (x_choose_y[x][y] == 0) {
    int without_y = ComputeXChooseY(x - 1, y, x_choose_y_ptr);
    int with_y = ComputeXChooseY(x - 1, y - 1, x_choose_y_ptr);
    x_choose_y[x][y] = without_y + with_y;
  }
  return x_choose_y[x][y];
}

int ComputeBinomialCoefficientsSpaceEfficient(int n, int k) {
  k = min(k, n - k);
  vector<int> table(k + 1, 0);
  table[0] = 1;  // C(0, 0).
  // C(i, j) = C(i - 1, j) + C(i - 1, j - 1).
  for (int i = 1; i <= n; ++i) {
    for (int j = min(i, k); j >= 1; --j) {
      table[j] = table[j] + table[j - 1];
    }
  }
  return table[k];
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"n", "k"};
  return GenericTestMain(args, "binomial_coefficients.cc", "binomial_coefficients.tsv", &ComputeBinomialCoefficient,
                         DefaultComparator{}, param_names);
}
// clang-format on
