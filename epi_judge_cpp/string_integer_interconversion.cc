#include <string>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"

using std::string;

string IntToString(int x) {
  // Implement this placeholder.
  return "";
}

int StringToInt(const string& s) {
  // Implement this placeholder.
  return 0;
}

void Wrapper(int x, const string& s) {
  if (IntToString(x) != s) {
    throw TestFailure("Int to string conversion failed");
  }

  if (StringToInt(s) != x) {
    throw TestFailure("String to int conversion failed");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "s"};
  return GenericTestMain(args, "string_integer_interconversion.tsv", &Wrapper,
                         DefaultComparator{}, param_names);
}
