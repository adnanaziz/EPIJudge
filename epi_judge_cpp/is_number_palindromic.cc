
bool IsPalindromeNumber(int x) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  GenericTestMain(args, "is_number_palindromic.tsv", &IsPalindromeNumber,
                  DefaultComparator{}, param_names);
  return 0;
}
