#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

// A is passed by value argument, since we change it.
int FindFirstMissingPositive(vector<int> A) {
  // TODO - you fill in here.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "first_missing_positive_entry.cc",
                         "first_missing_positive_entry.tsv",
                         &FindFirstMissingPositive, DefaultComparator{},
                         param_names);
}
