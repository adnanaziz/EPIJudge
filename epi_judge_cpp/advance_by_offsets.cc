#include <vector>

using std::vector;

bool CanReachEnd(const vector<int>& max_advance_steps) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"max_advance_steps"};
  GenericTestMain(args, "advance_by_offsets.tsv", &CanReachEnd,
                  DefaultComparator{}, param_names);
  return 0;
}
