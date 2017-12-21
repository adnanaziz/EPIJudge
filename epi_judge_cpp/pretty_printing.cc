#include <string>
#include <vector>

using std::string;
using std::vector;

int MinimumMessiness(const vector<string>& words, int line_length) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "pretty_printing.tsv", &MinimumMessiness);
  return 0;
}
