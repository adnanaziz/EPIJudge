#include <string>

using std::string;

string SnakeString(const string& s) {
  // Implement this placeholder.
  return "";
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"s"};
  generic_test_main(argc, argv, param_names, "snake_string.tsv", &SnakeString);
  return 0;
}
