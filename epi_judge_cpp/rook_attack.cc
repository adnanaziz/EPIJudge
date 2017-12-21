#include <vector>

using std::vector;

void RookAttack(vector<vector<int>>* A_ptr) {
  // Implement this placeholder.
  return;
}

vector<vector<int>> RookAttackWrapper(vector<vector<int>> A) {
  RookAttack(&A);
  return A;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "rook_attack.tsv", &RookAttackWrapper);
  return 0;
}
