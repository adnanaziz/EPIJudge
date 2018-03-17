#include <vector>
#include "test_framework/generic_test.h"

using std::vector;

vector<vector<int>> GeneratePowerSet(const vector<int>& input_set) {
  // Implement this placeholder.
  return {};
}

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"input_set"};
  return GenericTestMain(
      args, timeout_seconds, "power_set.tsv", &GeneratePowerSet,
      &UnorderedComparator<vector<vector<int>>>, param_names);
}
