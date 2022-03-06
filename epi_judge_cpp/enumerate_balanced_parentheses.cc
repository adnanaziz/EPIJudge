#include <string>
#include <vector>

#include "test_framework/generic_test.h"
using std::string;
using std::vector;

void DirectedGenerateBalanceParantheses(int num_left_parantheses, int num_right_parantheses, 
    const string& paren, vector<string>& results) {

    if (!num_left_parantheses && !num_right_parantheses) {
        results.emplace_back(paren);
        return;
    }

    if (num_left_parantheses > 0) {
        DirectedGenerateBalanceParantheses(num_left_parantheses - 1, num_right_parantheses,
            paren + "(", results);
    }

    if (num_left_parantheses < num_right_parantheses) {
        DirectedGenerateBalanceParantheses(num_left_parantheses, num_right_parantheses - 1,
            paren + ")", results);
    }

} 

vector<string> GenerateBalancedParentheses(int num_pairs) {
    vector<string> results;
    DirectedGenerateBalanceParantheses(num_pairs, num_pairs, "", results);
    return results;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num_pairs"};
  return GenericTestMain(args, "enumerate_balanced_parentheses.cc",
                         "enumerate_balanced_parentheses.tsv",
                         &GenerateBalancedParentheses, UnorderedComparator{},
                         param_names);
}
