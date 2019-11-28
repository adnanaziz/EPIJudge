#include <string>
#include <vector>

#include "test_framework/generic_test.h"

using std::string;
using std::vector;

void DirectedGenerateBalancedParentheses(int, int, const string&,
                                         vector<string>*);

vector<string> GenerateBalancedParentheses(int num_pairs) {
  vector<string> result;
  DirectedGenerateBalancedParentheses(num_pairs, num_pairs,
                                      /*valid_prefix=*/"", &result);
  return result;
}

void DirectedGenerateBalancedParentheses(int num_left_parens_needed,
                                         int num_right_parens_needed,
                                         const string& valid_prefix,
                                         vector<string>* result) {
  if (!num_right_parens_needed) {
    result->emplace_back(valid_prefix);
    return;
  }

  if (num_left_parens_needed > 0) {  // Able to insert '('.
    DirectedGenerateBalancedParentheses(num_left_parens_needed - 1,
                                        num_right_parens_needed,
                                        valid_prefix + '(', result);
  }
  if (num_left_parens_needed < num_right_parens_needed) {
    // Able to insert ')'.
    DirectedGenerateBalancedParentheses(num_left_parens_needed,
                                        num_right_parens_needed - 1,
                                        valid_prefix + ')', result);
  }
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"num_pairs"};
  return GenericTestMain(args, "enumerate_balanced_parentheses.cc", "enumerate_balanced_parentheses.tsv", &GenerateBalancedParentheses,
                         UnorderedComparator{}, param_names);
}
// clang-format on
