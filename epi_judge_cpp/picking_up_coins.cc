#include <vector>

using std::vector;

int MaximumRevenue(const vector<int>& coins) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "picking_up_coins.tsv", &MaximumRevenue);
  return 0;
}
