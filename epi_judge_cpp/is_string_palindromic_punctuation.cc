#include <string>

using std::string;

bool IsPalindrome(const string& s) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  GenericTestMain(args, "is_string_palindromic_punctuation.tsv", &IsPalindrome,
                  DefaultComparator{}, param_names);
  return 0;
}
