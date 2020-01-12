#include <string>

#include "test_framework/generic_test.h"

using std::string;

bool IsPalindromic(const string& s) {
  for (int i = 0, j = size(s) - 1; i < j; ++i, --j) {
    if (s[i] != s[j]) {
      return false;
    }
  }
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "is_string_palindromic.cc",
                         "is_string_palindromic.tsv", &IsPalindromic,
                         DefaultComparator{}, param_names);
}
