#include <vector>

using std::vector;

// Given n, return all primes up to and including n.
vector<int> GeneratePrimes(int n) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"n"};
  generic_test_main(argc, argv, param_names, "prime_sieve.tsv",
                    &GeneratePrimes);
  return 0;
}
