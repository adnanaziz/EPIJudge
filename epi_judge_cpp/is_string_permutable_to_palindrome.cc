#include <string>

using std::string;

bool CanFormPalindrome(const string& s) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  GenericTestMain(args, "can_string_be_palindrome.tsv", &CanFormPalindrome,
                  DefaultComparator{}, param_names);
  return 0;
}
