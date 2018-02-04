#include <string>

using std::string;

string ConvertBase(const string& num_as_string, int b1, int b2) {
  // Implement this placeholder.
  return "";
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num_as_string", "b1", "b2"};
  GenericTestMain(args, "convert_base.tsv", &ConvertBase, DefaultComparator{},
                  param_names);
  return 0;
}
