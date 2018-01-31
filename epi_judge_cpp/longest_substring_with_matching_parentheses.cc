#include <string>
#include <vector>

using std::string;
using std::vector;

int LongestMatchingParentheses(const string& s) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"s"};
  generic_test_main(argc, argv, param_names,
                    "longest_substring_with_matching_parentheses.tsv",
                    &LongestMatchingParentheses);
  return 0;
}
