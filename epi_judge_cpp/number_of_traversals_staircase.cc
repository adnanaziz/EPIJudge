#include "test_framework/generic_test.h"

#include<vector>
using std::vector;

int ComputeNumberOfWaysToH(int h, int maximum_steps, vector<int>& number_of_ways_to_h) {
    if(h <= 1) {
        return 1;
    }

    if (number_of_ways_to_h[h] == 0) {
        for (int i = 1; i <= maximum_steps && h - i >= 0; i++) {
            number_of_ways_to_h[h] += ComputeNumberOfWaysToH(h - i, maximum_steps, number_of_ways_to_h);
        }
    }
    return number_of_ways_to_h[h];
}

int NumberOfWaysToTop(int top, int maximum_step) {
    vector<int> number_of_ways_to_h(top+1, 0);
    return ComputeNumberOfWaysToH(top, maximum_step, number_of_ways_to_h);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"top", "maximum_step"};
  return GenericTestMain(args, "number_of_traversals_staircase.cc",
                         "number_of_traversals_staircase.tsv",
                         &NumberOfWaysToTop, DefaultComparator{}, param_names);
}
