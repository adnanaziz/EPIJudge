#include <string>
#include <vector>

#include "test_framework/generic_test.h"
using std::string;
using std::vector;

vector<string> JustifyText(const vector<string>& words, int L) {
  // TODO - you fill in here.
  return {};
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"words", "L"};
  return GenericTestMain(args, "left_right_justify_text.cc",
                         "left_right_justify_text.tsv", &JustifyText,
                         DefaultComparator{}, param_names);
}
