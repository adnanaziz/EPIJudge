#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

bool TestCollatzConjecture(int n) {
  // TODO - you fill in here.
  return false;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "collatz_checker.cc", "collatz_checker.tsv",
                         &TestCollatzConjecture, DefaultComparator{},
                         param_names);
}
