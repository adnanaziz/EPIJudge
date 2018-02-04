#include <vector>

using std::vector;

vector<vector<int>> Permutations(vector<int> A) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  GenericTestMain(args, "permutations.tsv", &Permutations,
                  &UnorderedComparator<vector<vector<int>>>, param_names);
  return 0;
}
