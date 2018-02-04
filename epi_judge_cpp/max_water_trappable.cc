#include <vector>

using std::vector;

int CalculateTrappingWater(const vector<int>& heights) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"heights"};
  GenericTestMain(args, "max_water_trappable.tsv", &CalculateTrappingWater,
                  DefaultComparator{}, param_names);
  return 0;
}
