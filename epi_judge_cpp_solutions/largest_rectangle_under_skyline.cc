#include <algorithm>
#include <stack>
#include <vector>

#include "test_framework/generic_test.h"

using std::max;
using std::stack;
using std::vector;

bool IsNewPillarOrReachEnd(const vector<int>&, int, int);

int CalculateLargestRectangle(const vector<int>& heights) {
  stack<int> pillar_indices;
  int max_rectangle_area = 0;
  // By iterating to size(heights) instead of size(heights) - 1, we can
  // uniformly handle the computation for rectangle area here.
  for (int i = 0; i <= size(heights); ++i) {
    while (!empty(pillar_indices) &&
           IsNewPillarOrReachEnd(heights, i, pillar_indices.top())) {
      int height = heights[pillar_indices.top()];
      pillar_indices.pop();
      int width = empty(pillar_indices) ? i : i - pillar_indices.top() - 1;
      max_rectangle_area = max(max_rectangle_area, height * width);
    }
    pillar_indices.emplace(i);
  }
  return max_rectangle_area;
}

bool IsNewPillarOrReachEnd(const vector<int>& heights, int curr_idx,
                           int last_pillar_idx) {
  return curr_idx < size(heights)
             ? heights[curr_idx] <= heights[last_pillar_idx]
             : true;
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"heights"};
  return GenericTestMain(args, "largest_rectangle_under_skyline.cc", "largest_rectangle_under_skyline.tsv", &CalculateLargestRectangle,
                         DefaultComparator{}, param_names);
}
// clang-format on
