#include <string>

#include "test_framework/test_failure_exception.h"

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
    throw TestFailureException("Int to string conversion failed");
  }

  if (StringToInt(s) != x) {
    throw TestFailureException("String to int conversion failed");
  }
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"x", "s"};
  generic_test_main(argc, argv, param_names,
                    "string_integer_interconversion.tsv", &Wrapper);
  return 0;
}
