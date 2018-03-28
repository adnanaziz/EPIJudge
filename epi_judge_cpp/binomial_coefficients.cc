#include "test_framework/generic_test.h"

int ComputeBinomialCoefficient(int n, int k) {
  // Implement this placeholder.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n", "k"};
  return GenericTestMain(args, "binomial_coefficients.tsv",
                         &ComputeBinomialCoefficient, DefaultComparator{},
                         param_names);
}
