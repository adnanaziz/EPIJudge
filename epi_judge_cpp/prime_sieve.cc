#include <vector>

using std::vector;

// Given n, return all primes up to and including n.
vector<int> GeneratePrimes(int n) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  GenericTestMain(args, "prime_sieve.tsv", &GeneratePrimes, DefaultComparator{},
                  param_names);
  return 0;
}
