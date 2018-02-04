

int NumberOfWays(int n, int m) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n", "m"};
  GenericTestMain(args, "number_of_traversals_matrix.tsv", &NumberOfWays,
                  DefaultComparator{}, param_names);
  return 0;
}
