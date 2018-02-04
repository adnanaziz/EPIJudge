#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <vector>

#include "test_framework/random_sequence_checker.h"
#include "test_framework/test_timer.h"

using std::bind;
using std::iota;
using std::vector;

// Returns a random k-sized subset of {0, 1, ..., n - 1}.
vector<int> RandomSubset(int n, int k) {
  // Implement this placeholder.
  return {};
}

bool RandomSubsetRunner(TestTimer& timer, int n, int k) {
  vector<vector<int>> results;
  timer.Start();
  std::generate_n(back_inserter(results), 100000,
                  std::bind(RandomSubset, n, k));
  timer.Stop();

  int total_possible_outcomes = BinomialCoefficient(n, k);
  vector<int> A(n);
  iota(begin(A), end(A), 0);
  vector<vector<int>> combinations;
  for (int i = 0; i < BinomialCoefficient(n, k); ++i) {
    combinations.emplace_back(ComputeCombinationIdx(A, n, k, i));
  }
  vector<int> sequence;
  for (vector<int> result : results) {
    sort(begin(result), end(result));
    sequence.emplace_back(
        distance(begin(combinations),
                 find(begin(combinations), end(combinations), result)));
  }
  return CheckSequenceIsUniformlyRandom(sequence, total_possible_outcomes,
                                        0.01);
}

void RandomSubsetWrapper(TestTimer& timer, int n, int k) {
  RunFuncWithRetries(bind(RandomSubsetRunner, std::ref(timer), n, k));
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"timer", "n", "k"};
  GenericTestMain(args, "random_subset.tsv", &RandomSubsetWrapper,
                  DefaultComparator{}, param_names);
  return 0;
}
