#include <string>

using std::string;

string LookAndSay(int n) {
  // Implement this placeholder.
  return "";
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"n"};
  generic_test_main(argc, argv, param_names, "look_and_say.tsv", &LookAndSay);
  return 0;
}
