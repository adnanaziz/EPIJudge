#include <algorithm>
#include <cmath>
#include <memory>
#include <numeric>
#include <vector>

#include "test_framework/generic_test.h"

using std::make_unique;
using std::vector;

void DirectedPowerSet(const vector<int>&, int, vector<int>*,
                      vector<vector<int>>*);

vector<vector<int>> GeneratePowerSet(const vector<int>& input_set) {
  vector<vector<int>> power_set;
  DirectedPowerSet(input_set, 0, make_unique<vector<int>>().get(), &power_set);
  return power_set;
}

// Generate all subsets whose intersection with input_set[0], ...,
// input_set[to_be_selected - 1] is exactly selected_so_far.
void DirectedPowerSet(const vector<int>& input_set, int to_be_selected,
                      vector<int>* selected_so_far,
                      vector<vector<int>>* power_set) {
  if (to_be_selected == size(input_set)) {
    power_set->emplace_back(*selected_so_far);
    return;
  }
  // Generate all subsets that contain input_set[to_be_selected].
  selected_so_far->emplace_back(input_set[to_be_selected]);
  DirectedPowerSet(input_set, to_be_selected + 1, selected_so_far, power_set);
  // Generate all subsets that do not contain input_set[to_be_selected].
  selected_so_far->pop_back();
  DirectedPowerSet(input_set, to_be_selected + 1, selected_so_far, power_set);
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"input_set"};
  return GenericTestMain(args, "power_set.cc", "power_set.tsv", &GeneratePowerSet,
                         UnorderedComparator{}, param_names);
}
// clang-format on
