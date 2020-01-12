#include <memory>
#include <vector>

#include "test_framework/generic_test.h"

using std::make_unique;
using std::vector;

int ComputeNumberOfWaysToH(int, int, vector<int>*);

int NumberOfWaysToTop(int top, int maximum_step) {
  return ComputeNumberOfWaysToH(top, maximum_step,
                                make_unique<vector<int>>(top + 1, 0).get());
}

int ComputeNumberOfWaysToH(int h, int maximum_step,
                           vector<int>* number_of_ways_to_h_ptr) {
  if (h <= 1) {
    return 1;
  }

  vector<int>& number_of_ways_to_h = *number_of_ways_to_h_ptr;
  if (number_of_ways_to_h[h] == 0) {
    for (int i = 1; i <= maximum_step && h - i >= 0; ++i) {
      number_of_ways_to_h[h] +=
          ComputeNumberOfWaysToH(h - i, maximum_step, number_of_ways_to_h_ptr);
    }
  }
  return number_of_ways_to_h[h];
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"top", "maximum_step"};
  return GenericTestMain(args, "number_of_traversals_staircase.cc",
                         "number_of_traversals_staircase.tsv",
                         &NumberOfWaysToTop, DefaultComparator{}, param_names);
}
