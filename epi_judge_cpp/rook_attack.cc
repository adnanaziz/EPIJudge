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

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  GenericTestMain(args, "rook_attack.tsv", &RookAttackWrapper,
                  DefaultComparator{}, param_names);
  return 0;
}
