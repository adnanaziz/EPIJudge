#include <string>
#include <vector>

#include "test_framework/generic_test.h"
using std::string;
using std::vector;

int LongestMatchingParentheses(const string& s) {
    int max_len = 0, end = -1;
    std::stack<int> longest_paran_indx;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            longest_paran_indx.emplace(i);
        }
        else if(longest_paran_indx.empty()){
            end = i;
        }
        else {
            longest_paran_indx.pop();
            int start = longest_paran_indx.empty() ? end : longest_paran_indx.top();
            max_len = std::max(max_len, i - start);
        }
    }

    return max_len;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "longest_substring_with_matching_parentheses.cc",
                         "longest_substring_with_matching_parentheses.tsv",
                         &LongestMatchingParentheses, DefaultComparator{},
                         param_names);
}
