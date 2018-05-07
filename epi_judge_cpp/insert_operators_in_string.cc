#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

bool ExpressionSynthesis(const vector<int>& digits, int target) {
  // TODO - you fill in here.
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"digits", "target"};
  return GenericTestMain(args, "insert_operators_in_string.cc",
                         "insert_operators_in_string.tsv", &ExpressionSynthesis,
                         DefaultComparator{}, param_names);
}
