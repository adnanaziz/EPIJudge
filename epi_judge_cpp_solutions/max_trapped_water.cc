#include <algorithm>
#include <vector>

#include "test_framework/generic_test.h"

using std::max;
using std::min;
using std::vector;

int GetMaxTrappedWater(const vector<int>& heights) {
  int i = 0, j = size(heights) - 1, max_water = 0;
  while (i < j) {
    int width = j - i;
    max_water = max(max_water, width * min(heights[i], heights[j]));
    if (heights[i] > heights[j]) {
      --j;
    } else {  // heights[i] <= heights[j].
      ++i;
    }
  }
  return max_water;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"heights"};
  return GenericTestMain(args, "max_trapped_water.cc", "max_trapped_water.tsv",
                         &GetMaxTrappedWater, DefaultComparator{}, param_names);
}
