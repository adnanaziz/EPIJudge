#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

int GetMaxTrappedWater(const vector<int>& heights) {
    int maxWater = 0;
    int i = 0, j = heights.size() - 1;
    while (i < j) {
        maxWater = std::max(maxWater, (j - i) * std::min(heights[i], heights[j]));
        if(heights[i]>heights[j]){ 
            j--;
        }
        else if (heights[i] < heights[j]) {
            i++;
        }
        else {
            i++; j--;
        }
    }
    return maxWater;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"heights"};
  return GenericTestMain(args, "max_trapped_water.cc", "max_trapped_water.tsv",
                         &GetMaxTrappedWater, DefaultComparator{}, param_names);
}
