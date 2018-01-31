#include <string>

using std::string;

int Evaluate(const string& expression) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"expression"};
  generic_test_main(argc, argv, param_names, "evaluate_rpn.tsv", &Evaluate);
  return 0;
}
