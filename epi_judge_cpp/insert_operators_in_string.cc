#include <vector>

using std::vector;

bool ExpressionSynthesis(const vector<int>& digits, int target) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"digits", "target"};
  GenericTestMain(args, "insert_operators_in_string.tsv", &ExpressionSynthesis,
                  DefaultComparator{}, param_names);
  return 0;
}
