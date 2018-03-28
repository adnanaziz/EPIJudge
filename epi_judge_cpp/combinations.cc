#include <vector>
#include "test_framework/generic_test.h"

using std::vector;

vector<vector<int>> Combinations(int n, int k) {
  // Implement this placeholder.
  return {};
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n", "k"};
  return GenericTestMain(args, "combinations.tsv", &Combinations,
                         &UnorderedComparator<std::vector<std::vector<int>>>,
                         param_names);
}
