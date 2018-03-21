#include <string>
#include "test_framework/generic_test.h"

using std::string;

int Evaluate(const string& expression) {
  // Implement this placeholder.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"expression"};
  return GenericTestMain(args, "evaluate_rpn.tsv", &Evaluate,
                         DefaultComparator{}, param_names);
}
