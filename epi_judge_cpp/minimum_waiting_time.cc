#include <vector>

using std::vector;

int MinimumTotalWaitingTime(vector<int> service_times) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"service_times"};
  generic_test_main(argc, argv, param_names, "minimum_waiting_time.tsv",
                    &MinimumTotalWaitingTime);
  return 0;
}
