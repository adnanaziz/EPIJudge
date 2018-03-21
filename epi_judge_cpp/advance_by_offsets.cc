#include <vector>
#include "test_framework/generic_test.h"

using std::vector;

bool CanReachEnd(const vector<int>& max_advance_steps) {
  // Implement this placeholder.
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"max_advance_steps"};
  return GenericTestMain(args, "advance_by_offsets.tsv", &CanReachEnd,
                         DefaultComparator{}, param_names);
}
