#include <vector>

using std::vector;

bool ExpressionSynthesis(const vector<int>& digits, int target) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "insert_operators_in_string.tsv",
                    &ExpressionSynthesis);
  return 0;
}
