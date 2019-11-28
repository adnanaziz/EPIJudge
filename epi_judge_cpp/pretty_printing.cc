#include <string>
#include <vector>

#include "test_framework/generic_test.h"
using std::string;
using std::vector;

int MinimumMessiness(const vector<string>& words, int line_length) {
  // TODO - you fill in here.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"words", "line_length"};
  return GenericTestMain(args, "pretty_printing.cc", "pretty_printing.tsv",
                         &MinimumMessiness, DefaultComparator{}, param_names);
}
