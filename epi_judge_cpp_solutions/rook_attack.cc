#include <algorithm>
#include <vector>

#include "test_framework/generic_test.h"

using std::begin;
using std::end;
using std::vector;

void RookAttack(vector<vector<int>>* A_ptr) {
  vector<vector<int>>& A = *A_ptr;
  int m = size(A), n = size(A[0]);
  bool has_first_row_zero = find(begin(A[0]), end(A[0]), 0) != end(A[0]);
  bool has_first_column_zero = any_of(
      begin(A), end(A), [](const vector<int>& row) { return row[0] == 0; });

  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      if (!A[i][j]) {
        A[i][0] = A[0][j] = 0;
      }
    }
  }

  for (int i = 1; i < m; ++i) {
    if (!A[i][0]) {
      fill(next(begin(A[i])), end(A[i]), 0);
    }
  }

  for (int j = 1; j < n; ++j) {
    if (!A[0][j]) {
      for_each(next(begin(A)), end(A), [j](vector<int>& row) { row[j] = 0; });
    }
  }

  if (has_first_row_zero) {
    fill(begin(A[0]), end(A[0]), 0);
  }
  if (has_first_column_zero) {
    for_each(begin(A), end(A), [](vector<int>& row) { row[0] = 0; });
  }
}

vector<vector<int>> RookAttackWrapper(vector<vector<int>> A) {
  vector<vector<int>> a_copy = A;
  RookAttack(&a_copy);
  return a_copy;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "rook_attack.cc", "rook_attack.tsv",
                         &RookAttackWrapper, DefaultComparator{}, param_names);
}
