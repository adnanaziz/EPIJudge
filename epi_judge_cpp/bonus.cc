#include <vector>

using std::vector;

int CalculateBonus(const vector<int>& productivity) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "bonus.tsv", &CalculateBonus);
  return 0;
}
