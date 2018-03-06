#include <vector>

using std::vector;

int MinimumTotalWaitingTime(vector<int> service_times) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"service_times"};
  return GenericTestMain(args, timeout_seconds, "minimum_waiting_time.tsv",
                         &MinimumTotalWaitingTime, DefaultComparator{},
                         param_names);
}
