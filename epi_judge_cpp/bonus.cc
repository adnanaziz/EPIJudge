#include <vector>

using std::vector;

int CalculateBonus(const vector<int>& productivity) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"productivity"};
  generic_test_main(argc, argv, param_names, "bonus.tsv", &CalculateBonus);
  return 0;
}
