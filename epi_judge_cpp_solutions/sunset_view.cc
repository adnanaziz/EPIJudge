#include <iterator>
#include <stack>
#include <vector>

#include "test_framework/generic_test.h"

using std::stack;
using std::vector;

vector<int> ExamineBuildingsWithSunset(
    vector<int>::const_iterator sequence_begin,
    const vector<int>::const_iterator& sequence_end) {
  int building_idx = 0;
  struct BuildingWithHeight {
    int id, height;
  };
  stack<BuildingWithHeight> candidates;
  while (sequence_begin != sequence_end) {
    int building_height = *sequence_begin++;
    while (!empty(candidates) && building_height >= candidates.top().height) {
      candidates.pop();
    }
    candidates.emplace(BuildingWithHeight{building_idx++, building_height});
  }

  vector<int> buildings_with_sunset;
  while (!empty(candidates)) {
    buildings_with_sunset.emplace_back(candidates.top().id);
    candidates.pop();
  }
  return buildings_with_sunset;
}

vector<int> ExamineBuildingsWithSunsetWrapper(const vector<int>& sequence) {
  return ExamineBuildingsWithSunset(cbegin(sequence), cend(sequence));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sequence"};
  return GenericTestMain(args, "sunset_view.cc", "sunset_view.tsv",
                         &ExamineBuildingsWithSunsetWrapper,
                         DefaultComparator{}, param_names);
}
