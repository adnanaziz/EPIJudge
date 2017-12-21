#include <vector>

using std::vector;

int FindElementAppearsOnce(const vector<int>& A) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "element_appearing_once.tsv",
                    &FindElementAppearsOnce);
  return 0;
}
