#include <algorithm>
#include <iterator>
#include <limits>
#include <vector>

#include "test_framework/generic_test.h"

using std::distance;
using std::numeric_limits;
using std::vector;

template <typename Iter>
int TrappingWaterTillEnd(Iter, Iter);

int CalculateTrappingWater(const vector<int>& heights) {
  // Finds the index with maximum height.
  int max_h =
      distance(begin(heights), max_element(begin(heights), end(heights)));
  return TrappingWaterTillEnd(begin(heights), begin(heights) + max_h) +
         TrappingWaterTillEnd(rbegin(heights),
                              rbegin(heights) + size(heights) - 1 - max_h);
}

// Assume end is maximum height.
template <typename Iter>
int TrappingWaterTillEnd(Iter begin, Iter end) {
  int sum = 0, highest_level_seen = numeric_limits<int>::min();
  for (Iter iter = begin; iter != end; ++iter) {
    if (*iter >= highest_level_seen) {
      highest_level_seen = *iter;
    } else {
      sum += highest_level_seen - *iter;
    }
  }
  return sum;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"heights"};
  return GenericTestMain(args, "max_water_trappable.cc",
                         "max_water_trappable.tsv", &CalculateTrappingWater,
                         DefaultComparator{}, param_names);
}
