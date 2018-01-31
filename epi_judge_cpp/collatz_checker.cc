#include <vector>

using std::vector;

bool TestCollatzConjecture(int n) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"n"};
  generic_test_main(argc, argv, param_names, "collatz_checker.tsv",
                    &TestCollatzConjecture);
  return 0;
}
