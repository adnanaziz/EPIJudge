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

bool OnlineRandomSamplingRunner(TestTimer& timer, vector<int> stream, int k) {
  vector<vector<int>> results;
  timer.Start();
  std::generate_n(
      back_inserter(results), 100000,
      std::bind(OnlineRandomSample, cbegin(stream), cend(stream), k));
  timer.Stop();

  int total_possible_outcomes = BinomialCoefficient(stream.size(), k);
  sort(begin(stream), end(stream));
  vector<vector<int>> combinations;
  for (int i = 0; i < BinomialCoefficient(stream.size(), k); ++i) {
    combinations.emplace_back(
        ComputeCombinationIdx(stream, stream.size(), k, i));
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

void OnlineRandomSampleWrapper(TestTimer& timer, const vector<int>& stream,
                               int k) {
  RunFuncWithRetries(
      bind(OnlineRandomSamplingRunner, std::ref(timer), std::cref(stream), k));
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"timer", "stream", "k"};
  GenericTestMain(args, "online_sampling.tsv", &OnlineRandomSampleWrapper,
                  DefaultComparator{}, param_names);
  return 0;
}
