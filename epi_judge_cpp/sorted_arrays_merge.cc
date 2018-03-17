#include <vector>
#include "test_framework/generic_test.h"

using std::vector;

vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays) {
  // Implement this placeholder.
  return {};
}

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sorted_arrays"};
  return GenericTestMain(args, timeout_seconds, "sorted_arrays_merge.tsv",
                         &MergeSortedArrays, DefaultComparator{}, param_names);
}
