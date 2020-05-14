#include <algorithm>
#include <deque>
#include <limits>
#include <vector>

#include "test_framework/generic_test.h"

using std::deque;
using std::max;
using std::min;
using std::numeric_limits;
using std::vector;

int MaxRectangleSubmatrix(const vector<deque<bool>>& A) {
  struct MaxHW {
    int h, w;
  };
  // DP table stores (h, w) for each (i, j).
  vector<vector<MaxHW>> table(size(A), vector<MaxHW>(size(A.front())));

  for (int i = size(A) - 1; i >= 0; --i) {
    for (int j = size(A[i]) - 1; j >= 0; --j) {
      // Find the largest h such that (i, j) to (i + h - 1, j) are feasible.
      // Find the largest w such that (i, j) to (i, j + w - 1) are feasible.
      table[i][j] = A[i][j]
                        ? MaxHW{i + 1 < size(A) ? table[i + 1][j].h + 1 : 1,
                                j + 1 < size(A[i]) ? table[i][j + 1].w + 1 : 1}
                        : MaxHW{0, 0};
    }
  }

  int max_rectangle_area = 0;
  for (int i = 0; i < size(A); ++i) {
    for (int j = 0; j < size(A[i]); ++j) {
      // Process (i, j) if it is feasible and is possible to update
      // max_rectangle_area.
      if (A[i][j] && table[i][j].w * table[i][j].h > max_rectangle_area) {
        int min_width = numeric_limits<int>::max();
        for (int a = 0; a < table[i][j].h; ++a) {
          min_width = min(min_width, table[i + a][j].w);
          max_rectangle_area = max(max_rectangle_area, min_width * (a + 1));
        }
      }
    }
  }
  return max_rectangle_area;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "max_submatrix.cc", "max_submatrix.tsv",
                         &MaxRectangleSubmatrix, DefaultComparator{},
                         param_names);
}
