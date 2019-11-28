#include <cctype>
#include <string>

#include "test_framework/generic_test.h"

using std::string;

bool IsPalindrome(const string& s) {
  // i moves forward, and j moves backward.
  int i = 0, j = size(s) - 1;
  while (i < j) {
    // i and j both skip non-alphanumeric characters.
    while (!isalnum(s[i]) && i < j) {
      ++i;
    }
    while (!isalnum(s[j]) && i < j) {
      --j;
    }
    if (tolower(s[i++]) != tolower(s[j--])) {
      return false;
    }
  }
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "is_string_palindromic_punctuation.cc",
                         "is_string_palindromic_punctuation.tsv", &IsPalindrome,
                         DefaultComparator{}, param_names);
}
