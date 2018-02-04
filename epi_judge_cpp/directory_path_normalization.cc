#include <string>

using std::string;

string ShortestEquivalentPath(const string& path) {
  // Implement this placeholder.
  return "";
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"path"};
  GenericTestMain(args, "directory_path_normalization.tsv",
                  &ShortestEquivalentPath, DefaultComparator{}, param_names);
  return 0;
}
