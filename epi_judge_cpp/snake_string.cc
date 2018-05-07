#include <string>
#include "test_framework/generic_test.h"
using std::string;

string SnakeString(const string& s) {
  // TODO - you fill in here.
  return "";
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "snake_string.cc", "snake_string.tsv",
                         &SnakeString, DefaultComparator{}, param_names);
}
