#include "test_framework/generic_test.h"

int NumberOfWaysToTop(int top, int maximum_step) {
  // TODO - you fill in here.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"top", "maximum_step"};
  return GenericTestMain(args, "number_of_traversals_staircase.cc",
                         "number_of_traversals_staircase.tsv",
                         &NumberOfWaysToTop, DefaultComparator{}, param_names);
}
