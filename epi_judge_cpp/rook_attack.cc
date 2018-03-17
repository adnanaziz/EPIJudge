#include <vector>
#include "test_framework/generic_test.h"

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

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, timeout_seconds, "rook_attack.tsv",
                         &RookAttackWrapper, DefaultComparator{}, param_names);
}
