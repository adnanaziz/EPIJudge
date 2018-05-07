#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

int CalculateLargestRectangle(const vector<int>& heights) {
  // TODO - you fill in here.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"heights"};
  return GenericTestMain(args, "largest_rectangle_under_skyline.cc",
                         "largest_rectangle_under_skyline.tsv",
                         &CalculateLargestRectangle, DefaultComparator{},
                         param_names);
}
