#include <string>

using std::string;

bool IsMatch(const string &regex, const string &s) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char *argv[]) {
  generic_test_main(argc, argv, "regular_expression.tsv", &IsMatch);
  return 0;
}
