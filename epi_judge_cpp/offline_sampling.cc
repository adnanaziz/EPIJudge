#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>

#include "test_framework/random_sequence_checker.h"
#include "test_framework/test_timer.h"

using std::bind;
using std::vector;

void RandomSampling(int k, vector<int>* A_ptr) {
  // Implement this placeholder.
  return;
}

bool RandomSamplingRunner(TestTimer& timer, int k, vector<int> A) {
  vector<vector<int>> results;
  timer.Start();
  for (int i = 0; i < 100000; ++i) {
    RandomSampling(k, &A);
    results.emplace_back(begin(A), begin(A) + k);
  }
  timer.Stop();

  int total_possible_outcomes = BinomialCoefficient(A.size(), k);
  sort(begin(A), end(A));
  vector<vector<int>> combinations;
  for (int i = 0; i < BinomialCoefficient(A.size(), k); ++i) {
    combinations.emplace_back(ComputeCombinationIdx(A, A.size(), k, i));
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

void RandomSamplingWrapper(TestTimer& timer, int k, const vector<int>& A) {
  RunFuncWithRetries(bind(RandomSamplingRunner, timer, k, A));
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "offline_sampling.tsv", &RandomSamplingWrapper);
  return 0;
}
