#include <string>
#include <unordered_set>

#include "test_framework/generic_test.h"
using std::string;
using std::unordered_set;

int TransformString(unordered_set<string> D, const string& s, const string& t) {
  // TODO - you fill in here.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"D", "s", "t"};
  return GenericTestMain(args, "string_transformability.cc",
                         "string_transformability.tsv", &TransformString,
                         DefaultComparator{}, param_names);
}
