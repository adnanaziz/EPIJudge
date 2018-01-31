#include <string>
#include <vector>

using std::string;
using std::vector;

vector<string> GenerateBalancedParentheses(int num_pairs) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"num_pairs"};
  generic_test_main(
      argc, argv, param_names, "enumerate_balanced_parentheses.tsv",
      &GenerateBalancedParentheses, &UnorderedComparator<vector<string>>);
  return 0;
}
