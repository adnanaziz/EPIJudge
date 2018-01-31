#include <vector>

using std::vector;

int FindBiggestNMinusOneProduct(const vector<int>& A) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"A"};
  generic_test_main(argc, argv, param_names, "max_product_all_but_one.tsv",
                    &FindBiggestNMinusOneProduct);
  return 0;
}
