#include <vector>

using std::vector;

vector<vector<int>> GeneratePowerSet(const vector<int>& input_set) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "power_set.tsv", &GeneratePowerSet,
                    &UnorderedComparator<vector<vector<int>>>);
  return 0;
}
