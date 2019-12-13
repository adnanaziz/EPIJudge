#include <string>

#include "test_framework/generic_test.h"
using std::string;

bool IsMatch(const string &regex, const string &s) {
  // TODO - you fill in here.
  return true;
}

int main(int argc, char *argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"regex", "s"};
  return GenericTestMain(args, "regular_expression.cc",
                         "regular_expression.tsv", &IsMatch,
                         DefaultComparator{}, param_names);
}
