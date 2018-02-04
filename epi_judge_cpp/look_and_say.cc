#include <string>

using std::string;

string LookAndSay(int n) {
  // Implement this placeholder.
  return "";
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  GenericTestMain(args, "look_and_say.tsv", &LookAndSay, DefaultComparator{},
                  param_names);
  return 0;
}
