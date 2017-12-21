#include <string>

using std::string;

bool IsPalindrome(const string& s) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "is_string_palindromic_punctuation.tsv",
                    &IsPalindrome);
  return 0;
}
