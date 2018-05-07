#include "test_framework/generic_test.h"

int GetHeight(int cases, int drops) {
  // TODO - you fill in here.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"cases", "drops"};
  return GenericTestMain(args, "max_safe_height.cc", "max_safe_height.tsv",
                         &GetHeight, DefaultComparator{}, param_names);
}
