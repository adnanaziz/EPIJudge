#include <algorithm>
#include <functional>
#include <iterator>
#include <random>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/random_sequence_checker.h"
#include "test_framework/timed_executor.h"

using std::bind;
using std::default_random_engine;
using std::random_device;
using std::sort;
using std::uniform_int_distribution;
using std::vector;

// Assumption: there are at least k elements in the stream.
vector<int> OnlineRandomSample(vector<int>::const_iterator stream_begin,
                               const vector<int>::const_iterator stream_end,
                               int k) {
  vector<int> running_sample;
  // Storesult the first k elements.
  for (int i = 0; i < k; ++i) {
    running_sample.emplace_back(*stream_begin++);
  }

  default_random_engine seed((random_device())());  // Random num generator.
  // Have read the first k elements.
  int num_seen_so_far = k;
  while (stream_begin != stream_end) {
    int x = *stream_begin++;
    ++num_seen_so_far;
    // Generate a random number in [0, num_seen_so_far - 1], and if this
    // number is in [0, k - 1], we replace that element from the sample with
    // x.
    if (const int idx_to_replace =
            uniform_int_distribution<int>{0, num_seen_so_far - 1}(seed);
        idx_to_replace < k) {
      running_sample[idx_to_replace] = x;
    }
  }
  return running_sample;
}

bool OnlineRandomSamplingRunner(TimedExecutor& executor, vector<int> stream,
                                int k) {
  using namespace test_framework;
  vector<vector<int>> results;

  executor.Run([&] {
    std::generate_n(
        back_inserter(results), 100000,
        std::bind(OnlineRandomSample, cbegin(stream), cend(stream), k));
  });

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

void OnlineRandomSampleWrapper(TimedExecutor& executor,
                               const vector<int>& stream, int k) {
  RunFuncWithRetries(bind(OnlineRandomSamplingRunner, std::ref(executor),
                          std::cref(stream), k));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "stream", "k"};
  return GenericTestMain(args, "online_sampling.cc", "online_sampling.tsv",
                         &OnlineRandomSampleWrapper, DefaultComparator{},
                         param_names);
}
