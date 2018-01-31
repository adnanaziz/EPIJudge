#include <string>
#include <unordered_set>

using std::string;
using std::unordered_set;

// Uses BFS to find the least steps of transformation.
int TransformString(unordered_set<string> D, const string& s, const string& t) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"D", "s", "t"};
  generic_test_main(argc, argv, param_names, "string_transformability.tsv",
                    &TransformString);
  return 0;
}
