#include <vector>

using std::vector;

int CalculateTrappingWater(const vector<int>& heights) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"heights"};
  generic_test_main(argc, argv, param_names, "max_water_trappable.tsv",
                    &CalculateTrappingWater);
  return 0;
}
