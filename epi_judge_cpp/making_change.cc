#include "test_framework/generic_test.h"

int ChangeMaking(int cents) {
  // TODO - you fill in here.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"cents"};
  return GenericTestMain(args, "making_change.cc", "making_change.tsv",
                         &ChangeMaking, DefaultComparator{}, param_names);
}
