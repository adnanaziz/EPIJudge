#include <string>
#include "test_framework/generic_test.h"
using std::string;
string ShortestEquivalentPath(const string& path) {
  // TODO - you fill in here.
  return "";
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"path"};
  return GenericTestMain(args, "directory_path_normalization.cc",
                         "directory_path_normalization.tsv",
                         &ShortestEquivalentPath, DefaultComparator{},
                         param_names);
}
