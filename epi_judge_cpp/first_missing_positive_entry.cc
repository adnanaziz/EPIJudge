#include <vector>

using std::vector;

// A is passed by value argument, since we change it.
int FindFirstMissingPositive(vector<int> A) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"A"};
  generic_test_main(argc, argv, param_names, "first_missing_positive_entry.tsv",
                    &FindFirstMissingPositive);
  return 0;
}
