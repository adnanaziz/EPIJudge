#include <iterator>
#include <stack>
#include <string>
#include <unordered_map>

#include "test_framework/generic_test.h"

using std::stack;
using std::string;
using std::unordered_map;

bool IsWellFormed(const string& s) {
  stack<char> left_chars;
  const unordered_map<char, char> kLookup = {
      {'(', ')'}, {'{', '}'}, {'[', ']'}};
  for (int i = 0; i < size(s); ++i) {
    if (kLookup.count(s[i])) {
      left_chars.emplace(s[i]);
    } else {
      if (empty(left_chars) || kLookup.at(left_chars.top()) != s[i]) {
        // Unmatched right char or mismatched chars.
        return false;
      }
      left_chars.pop();
    }
  }
  return empty(left_chars);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "is_valid_parenthesization.cc",
                         "is_valid_parenthesization.tsv", &IsWellFormed,
                         DefaultComparator{}, param_names);
}
