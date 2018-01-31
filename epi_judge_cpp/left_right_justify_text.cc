#include <string>
#include <vector>

using std::string;
using std::vector;

vector<string> JustifyText(const vector<string>& words, int L) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"words", "L"};
  generic_test_main(argc, argv, param_names, "left_right_justify_text.tsv",
                    &JustifyText);
  return 0;
}
