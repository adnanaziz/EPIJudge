#include <cmath>
#include <deque>
#include <vector>

#include "test_framework/generic_test.h"

using std::deque;
using std::vector;

// Given n, return all primes up to and including n.
vector<int> GeneratePrimes(int n) {
  if (n < 2) {
    return {};
  }
  const int size = floor(0.5 * (n - 3)) + 1;
  vector<int> primes;
  primes.emplace_back(2);
  // is_prime[i] represents whether (2i + 3) is prime or not.
  // For example, is_prime[0] represents 3 is prime or not, is_prime[1]
  // represents 5, is_prime[2] represents 7, etc.
  // Initially, set each to true. Then use sieving to eliminate nonprimes.
  deque<bool> is_prime(size, true);
  for (int i = 0; i < size; ++i) {
    if (is_prime[i]) {
      int p = (i * 2) + 3;
      primes.emplace_back(p);
      // Sieving from p^2, whose value is (4i^2 + 12i + 9). The index in
      // is_prime is (2i^2 + 6i + 3) because is_prime[i] represents 2i + 3.
      //
      // Note that we need to use long long for j because p^2 might overflow.
      for (long long j = 2LL * i * i + 6 * i + 3; j < size; j += p) {
        is_prime[j] = false;
      }
    }
  }
  return primes;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "prime_sieve.cc", "prime_sieve.tsv",
                         &GeneratePrimes, DefaultComparator{}, param_names);
}
