#include <algorithm>
#include <deque>
#include <vector>

#include "test_framework/generic_test.h"

using std::deque;
using std::max;
using std::min;
using std::vector;

int MaxSquareSubmatrix(const vector<deque<bool>>& A) {
  struct MaxHW {
    int h, w;
  };
  // DP table stores (h, w) for each (i, j).
  vector<vector<MaxHW>> table(size(A), vector<MaxHW>(size(A.front())));

  for (int i = size(A) - 1; i >= 0; --i) {
    for (int j = size(A[i]) - 1; j >= 0; --j) {
      // Finds the largest h such that (i, j) to (i + h - 1, j) are feasible.
      // Finds the largest w such that (i, j) to (i, j + w - 1) are feasible.
      table[i][j] = A[i][j]
                        ? MaxHW{i + 1 < size(A) ? table[i + 1][j].h + 1 : 1,
                                j + 1 < size(A[i]) ? table[i][j + 1].w + 1 : 1}
                        : MaxHW{0, 0};
    }
  }

  // A table stores the length of the largest square for each (i, j).
  vector<vector<int>> s(size(A), vector<int>(size(A.front()), 0));
  int max_square_area = 0;
  for (int i = size(A) - 1; i >= 0; --i) {
    for (int j = size(A[i]) - 1; j >= 0; --j) {
      int side = min(table[i][j].h, table[i][j].w);
      if (A[i][j]) {
        // Gets the length of largest square with bottom-left corner (i, j).
        if (i + 1 < size(A) && j + 1 < size(A[i + 1])) {
          side = min(s[i + 1][j + 1] + 1, side);
        }
        s[i][j] = side;
        max_square_area = max(max_square_area, side * side);
      }
    }
  }
  return max_square_area;
}

int MaxSquareSubmatrixSpaceEfficient(const vector<deque<bool>>& A) {
  vector<int> pre(size(A.front()), 0);
  int max_side = 0;
  for (const deque<bool>& row : A) {
    vector<int> curr(begin(row), end(row));
    for (int j = 1; j < size(curr); ++j) {
      curr[j] *= (min({pre[j - 1], pre[j], curr[j - 1]}) + 1);
    }
    max_side = max(max_side, *max_element(begin(curr), end(curr)));
    pre = move(curr);
  }
  return max_side * max_side;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "max_square_submatrix.cc",
                         "max_square_submatrix.tsv", &MaxSquareSubmatrix,
                         DefaultComparator{}, param_names);
}
