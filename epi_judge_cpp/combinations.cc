#include <vector>

using std::vector;

vector<vector<int>> Combinations(int n, int k) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n", "k"};
  GenericTestMain(args, "combinations.tsv", &Combinations,
                  &UnorderedComparator<std::vector<std::vector<int>>>,
                  param_names);
  return 0;
}
