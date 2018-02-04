

int ComputeBinomialCoefficient(int n, int k) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n", "k"};
  GenericTestMain(args, "binomial_coefficients.tsv",
                  &ComputeBinomialCoefficient, DefaultComparator{},
                  param_names);
  return 0;
}
