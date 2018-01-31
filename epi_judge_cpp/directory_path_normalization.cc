#include <string>

using std::string;

string ShortestEquivalentPath(const string& path) {
  // Implement this placeholder.
  return "";
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"path"};
  generic_test_main(argc, argv, param_names, "directory_path_normalization.tsv",
                    &ShortestEquivalentPath);
  return 0;
}
