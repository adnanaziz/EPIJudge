

int NumberOfWaysToTop(int top, int maximum_step) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"top", "maximum_step"};
  GenericTestMain(args, "number_of_traversals_staircase.tsv",
                  &NumberOfWaysToTop, DefaultComparator{}, param_names);
  return 0;
}
