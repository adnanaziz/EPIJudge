#include <string>
#include "test_framework/generic_test.h"

using std::string;

int RomanToInteger(const string& s) {
  // Implement this placeholder.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "roman_to_integer.tsv", &RomanToInteger,
                         DefaultComparator{}, param_names);
}
