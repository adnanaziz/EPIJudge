#include <string>

using std::string;

bool IsWellFormed(const string& s) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  GenericTestMain(args, "is_valid_parenthesization.tsv", &IsWellFormed,
                  DefaultComparator{}, param_names);
  return 0;
}
