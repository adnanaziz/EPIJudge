#include <algorithm>
#include <vector>

#include "test_framework/generic_test.h"

using std::max;
using std::vector;

bool CanReachEnd(const vector<int>& max_advance_steps) {
  int furthest_reach_so_far = 0, last_index = size(max_advance_steps) - 1;
  for (int i = 0;
       i <= furthest_reach_so_far && furthest_reach_so_far < last_index; ++i) {
    furthest_reach_so_far =
        max(furthest_reach_so_far, max_advance_steps[i] + i);
  }
  return furthest_reach_so_far >= last_index;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"max_advance_steps"};
  return GenericTestMain(args, "advance_by_offsets.cc",
                         "advance_by_offsets.tsv", &CanReachEnd,
                         DefaultComparator{}, param_names);
}
