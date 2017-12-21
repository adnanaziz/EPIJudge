#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>

#include "test_framework/random_sequence_checker.h"
#include "test_framework/test_timer.h"

using std::bind;
using std::sort;
using std::vector;

// Assumption: there are at least k elements in the stream.
vector<int> OnlineRandomSample(vector<int>::const_iterator stream_begin,
                               const vector<int>::const_iterator stream_end,
                               int k) {
  // Implement this placeholder.
  return {};
}

bool OnlineRandomSamplingRunner(TestTimer& timer, vector<int> A, int k) {
  vector<vector<int>> results;
  timer.Start();
  std::generate_n(back_inserter(results), 100000,
                  std::bind(OnlineRandomSample, cbegin(A), cend(A), k));
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

void OnlineRandomSampleWrapper(TestTimer& timer, vector<int> A, int k) {
  RunFuncWithRetries(bind(OnlineRandomSamplingRunner, timer, A, k));
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "online_sampling.tsv",
                    &OnlineRandomSampleWrapper);
  return 0;
}
