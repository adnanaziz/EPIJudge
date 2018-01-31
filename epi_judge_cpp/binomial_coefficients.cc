

int ComputeBinomialCoefficient(int n, int k) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"n", "k"};
  generic_test_main(argc, argv, param_names, "binomial_coefficients.tsv",
                    &ComputeBinomialCoefficient);
  return 0;
}
