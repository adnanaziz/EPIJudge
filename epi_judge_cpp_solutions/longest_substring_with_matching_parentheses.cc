#include <algorithm>
#include <stack>
#include <string>
#include <vector>

#include "test_framework/generic_test.h"

using std::max;
using std::stack;
using std::string;
using std::vector;

int LongestMatchingParentheses(const string& s) {
  int max_length = 0, end = -1;
  stack<int> left_parentheses_indices;
  for (int i = 0; i < size(s); ++i) {
    if (s[i] == '(') {
      left_parentheses_indices.emplace(i);
    } else if (empty(left_parentheses_indices)) {
      end = i;
    } else {
      left_parentheses_indices.pop();
      int start = empty(left_parentheses_indices)
                      ? end
                      : left_parentheses_indices.top();
      max_length = max(max_length, i - start);
    }
  }
  return max_length;
}

template <typename IterType>
int ParseFromSide(char paren, IterType begin, IterType end) {
  int max_length = 0, num_parens_so_far = 0, length = 0;
  for (IterType i = begin; i < end; ++i) {
    if (*i == paren) {
      ++num_parens_so_far, ++length;
    } else {  // *i != paren
      if (num_parens_so_far <= 0) {
        num_parens_so_far = length = 0;
      } else {
        --num_parens_so_far, ++length;
        if (num_parens_so_far == 0) {
          max_length = max(max_length, length);
        }
      }
    }
  }
  return max_length;
}

int LongestMatchingParenthesesConstantSpace(const string& s) {
  return max(ParseFromSide('(', begin(s), end(s)),
             ParseFromSide(')', rbegin(s), rend(s)));
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"s"};
  return GenericTestMain(args, "longest_substring_with_matching_parentheses.cc", "longest_substring_with_matching_parentheses.tsv", &LongestMatchingParentheses,
                         DefaultComparator{}, param_names);
}
// clang-format on
