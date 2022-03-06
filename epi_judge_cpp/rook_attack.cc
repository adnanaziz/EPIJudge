#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

void RookAttack(vector<vector<int>>* A_ptr) {
    vector<vector<int>>& A = *A_ptr;
    bool first_row_has_zero = false, first_column_has_zero = false;

    int m = A.size(), n = A[0].size();

    for (int i = 0; i < m; i++){
        if (!A[i][0]) {
            first_column_has_zero = true;
            break;
        }
    }

    for (int j = 0; j < n; j++) {
        if (!A[0][j]) {
            first_row_has_zero = true;
            break;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (!A[i][j]) {
                A[i][0] = A[0][j] = 0;
            }
        }
    }
    
    for (int j = 0; j < n; j++) {
        if (!A[0][j]) {
            for (int i = 0; i < m;i++) {
                A[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++){
        if (!A[i][0]) {
            for (int j = 0; j < n; j++){
                A[i][j] = 0;
            }
        }
    }

    if (first_row_has_zero) {
        for (int j = 0; j < n; j++) {
            A[0][j] = 0;
        }
    }

    if (first_column_has_zero) {
        for (int i = 0; i < m; i++) {
            A[i][0] = 0;
        }
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
