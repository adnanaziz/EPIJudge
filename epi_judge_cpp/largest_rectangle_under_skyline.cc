#include <vector>

using std::vector;

int CalculateLargestRectangle(const vector<int>& heights) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"heights"};
  GenericTestMain(args, "largest_rectangle_under_skyline.tsv",
                  &CalculateLargestRectangle, DefaultComparator{}, param_names);
  return 0;
}
