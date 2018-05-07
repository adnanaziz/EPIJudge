#include <cmath>
#include <vector>
#include "test_framework/generic_test.h"

using std::vector;

vector<vector<int>> GeneratePowerSet(const vector<int>& input_set) {
  vector<vector<int>> power_set;
  for (int int_for_subset = 0; int_for_subset < (1 << size(input_set));
       ++int_for_subset) {
    int bit_array = int_for_subset;
    vector<int> subset;
    while (bit_array) {
      subset.emplace_back(input_set[log2(bit_array & ~(bit_array - 1))]);
      bit_array &= bit_array - 1;
    }
    power_set.emplace_back(subset);
  }
  return power_set;
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"input_set"};
  return GenericTestMain(args, "power_set.cc", "power_set.tsv", &GeneratePowerSet, &UnorderedComparator<vector<vector<int>>>, param_names);
}
// clang-format on
