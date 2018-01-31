#include <iterator>
#include <vector>

using std::vector;

vector<int> ExamineBuildingsWithSunset(
    vector<int>::const_iterator sequence_begin,
    const vector<int>::const_iterator& sequence_end) {
  // Implement this placeholder.
  return {};
}

vector<int> ExamineBuildingsWithSunsetWrapper(const vector<int>& sequence) {
  return ExamineBuildingsWithSunset(cbegin(sequence), cend(sequence));
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"sequence"};
  generic_test_main(argc, argv, param_names, "sunset_view.tsv",
                    &ExamineBuildingsWithSunsetWrapper);
  return 0;
}
