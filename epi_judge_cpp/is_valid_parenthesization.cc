#include <string>

using std::string;

bool IsWellFormed(const string& s) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "is_valid_parenthesization.tsv", &IsWellFormed);
  return 0;
}
