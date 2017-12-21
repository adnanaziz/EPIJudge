#include <string>

using std::string;

string ShortestEquivalentPath(const string& path) {
  // Implement this placeholder.
  return "";
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "directory_path_normalization.tsv",
                    &ShortestEquivalentPath);
  return 0;
}
