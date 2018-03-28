#include <string>
#include <vector>
#include "test_framework/generic_test.h"

using std::string;
using std::vector;

vector<string> GenerateBalancedParentheses(int num_pairs) {
  // Implement this placeholder.
  return {};
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num_pairs"};
  return GenericTestMain(args, "enumerate_balanced_parentheses.tsv",
                         &GenerateBalancedParentheses,
                         &UnorderedComparator<vector<string>>, param_names);
}
