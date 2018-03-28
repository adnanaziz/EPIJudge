#include <vector>
#include "test_framework/generic_test.h"

using std::vector;

// Given n, return all primes up to and including n.
vector<int> GeneratePrimes(int n) {
  // Implement this placeholder.
  return {};
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "prime_sieve.tsv", &GeneratePrimes,
                         DefaultComparator{}, param_names);
}
