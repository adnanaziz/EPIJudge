#include <string>

using std::string;

string LookAndSay(int n) {
  // Implement this placeholder.
  return "";
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "look_and_say.tsv", &LookAndSay);
  return 0;
}
