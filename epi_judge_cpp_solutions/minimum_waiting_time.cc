#include <algorithm>
#include <iterator>
#include <vector>

#include "test_framework/generic_test.h"

using std::vector;

int MinimumTotalWaitingTime(vector<int> service_times) {
  // Sort the service times in increasing order.
  sort(begin(service_times), end(service_times));

  int total_waiting_time = 0;
  for (int i = 0; i < size(service_times); ++i) {
    int num_remaining_queries = size(service_times) - (i + 1);
    total_waiting_time += service_times[i] * num_remaining_queries;
  }
  return total_waiting_time;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"service_times"};
  return GenericTestMain(args, "minimum_waiting_time.cc",
                         "minimum_waiting_time.tsv", &MinimumTotalWaitingTime,
                         DefaultComparator{}, param_names);
}
