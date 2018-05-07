#include <string>
#include "test_framework/generic_test.h"
using std::string;

string LookAndSay(int n) {
  // TODO - you fill in here.
  return "";
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "look_and_say.cc", "look_and_say.tsv",
                         &LookAndSay, DefaultComparator{}, param_names);
}
