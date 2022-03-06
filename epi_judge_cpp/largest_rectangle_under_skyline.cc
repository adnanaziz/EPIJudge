#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

bool IsNewPillarOrEnd(const vector<int>& heights, int curr_indx, int prev_pillar_pos) {
    return curr_indx < heights.size() ? heights[curr_indx] < heights[prev_pillar_pos] : true;
}

int CalculateLargestRectangle(const vector<int>& heights) {
    std::stack<int> pillar_position;
    int maxRectangle = 0;

    for (int i = 0; i <= heights.size(); i++) {
    
        if (i < heights.size() && !pillar_position.empty() && 
            heights[i] == heights[pillar_position.top()]) {
            pillar_position.pop();
            pillar_position.emplace(i);
        }
    
        while (!pillar_position.empty() && IsNewPillarOrEnd(heights, i, pillar_position.top())) {
            int height = heights[pillar_position.top()];
            pillar_position.pop();
        
            int width = pillar_position.empty() ? i : i - pillar_position.top() - 1;

            maxRectangle = std::max(maxRectangle, width * height);
        }
        pillar_position.emplace(i);
    }
    
    return maxRectangle;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"heights"};
  return GenericTestMain(args, "largest_rectangle_under_skyline.cc",
                         "largest_rectangle_under_skyline.tsv",
                         &CalculateLargestRectangle, DefaultComparator{},
                         param_names);
}
