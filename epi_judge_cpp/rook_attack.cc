#include <vector>

using std::vector;

void RookAttack(vector<vector<int>>* A_ptr) {
  // Implement this placeholder.
  return;
}

vector<vector<int>> RookAttackWrapper(vector<vector<int>> A) {
  vector<vector<int>> a_copy = A;
  RookAttack(&a_copy);
  return a_copy;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"A"};
  generic_test_main(argc, argv, param_names, "rook_attack.tsv",
                    &RookAttackWrapper);
  return 0;
}
