#include <string>

using std::string;

// Returns the index of the first character of the substring if found, -1
// otherwise.
int RabinKarp(const string &t, const string &s) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char *argv[]) {
  std::vector<std::string> param_names{"t", "s"};
  generic_test_main(argc, argv, param_names, "substring_match.tsv", &RabinKarp);
  return 0;
}
