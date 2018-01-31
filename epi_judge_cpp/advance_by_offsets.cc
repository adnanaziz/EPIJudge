#include <vector>

using std::vector;

bool CanReachEnd(const vector<int>& max_advance_steps) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"max_advance_steps"};
  generic_test_main(argc, argv, param_names, "advance_by_offsets.tsv",
                    &CanReachEnd);
  return 0;
}
