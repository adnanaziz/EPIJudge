#include <array>
#include <vector>

#include "test_framework/generic_test.h"

using std::array;
using std::vector;

int FindElementAppearsOnce(const vector<int> &A) {
  array<int, 32> counts = {};
  for (int x : A) {
    for (int i = 0; i < 32; ++i) {
      counts[i] += x & 1;
      x >>= 1;
    }
  }

  int result = 0;
  for (int i = 0; i < 32; ++i) {
    result |= (counts[i] % 3) << i;
  }
  return result;
}

int FindElementAppearsOnceAlternative(const vector<int> &A) {
  // ones denotes whether a bit-position has been set once (modulo 3) so far.
  // twos denotes whether a bit-position has been set twice (modulo 3) so far.
  int ones = 0, twos = 0;
  int next_ones, next_twos;
  for (const int &i : A) {
    // After reading A[i], bit-position j has a count of 1 modulo 3
    // if it had a count of 1 modulo 3 (the j-th bit in ones is set)
    // and the j-th bit in A[i] is 0 or the count was 0 modulo 3
    // (the j-th bit is not set in ones and in not set in twos) and
    // the j-th bit in A[i] is 1.
    next_ones = (~i & ones) | (i & ~ones & ~twos);

    // After reading A[i], bit-position j has a count of 2 modulo 3
    // if it had a count of 2 modulo 3 (the j-th bit in twos is set)
    // and the j-th bit in A[i] is a 0 or the count was 1 modulo 3
    // (the j-th bit is set in ones) and the j-th bit in A[i] is a 1.
    next_twos = (~i & twos) | (i & ones);

    ones = next_ones, twos = next_twos;
  }
  // Since ones denotes bit-positions which have been set once (modulo 3),
  // it is the element which appears only once.
  return ones;
}

int main(int argc, char *argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "element_appearing_once.cc",
                         "element_appearing_once.tsv", &FindElementAppearsOnce,
                         DefaultComparator{}, param_names);
}
