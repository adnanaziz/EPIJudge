

int GetHeight(int cases, int drops) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"cases", "drops"};
  generic_test_main(argc, argv, param_names, "max_safe_height.tsv", &GetHeight);
  return 0;
}
