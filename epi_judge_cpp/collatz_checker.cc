#include <vector>

using std::vector;

bool TestCollatzConjecture(int n) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  GenericTestMain(args, "collatz_checker.tsv", &TestCollatzConjecture,
                  DefaultComparator{}, param_names);
  return 0;
}
