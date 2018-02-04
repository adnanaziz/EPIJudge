#include <vector>

using std::vector;

vector<vector<int>> GeneratePowerSet(const vector<int>& input_set) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"input_set"};
  GenericTestMain(args, "power_set.tsv", &GeneratePowerSet,
                  &UnorderedComparator<vector<vector<int>>>, param_names);
  return 0;
}
