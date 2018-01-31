
bool IsPalindromeNumber(int x) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"x"};
  generic_test_main(argc, argv, param_names, "is_number_palindromic.tsv",
                    &IsPalindromeNumber);
  return 0;
}
