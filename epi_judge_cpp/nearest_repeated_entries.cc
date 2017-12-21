#include <string>
#include <vector>

using std::string;
using std::vector;

int FindNearestRepetition(const vector<string>& paragraph) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "nearest_repeated_entries.tsv",
                    &FindNearestRepetition);
  return 0;
}
