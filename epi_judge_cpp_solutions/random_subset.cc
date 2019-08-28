#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <random>
#include <unordered_map>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/random_sequence_checker.h"
#include "test_framework/timed_executor.h"

using std::bind;
using std::default_random_engine;
using std::iota;
using std::random_device;
using std::uniform_int_distribution;
using std::unordered_map;
using std::vector;

// Returns a random k-sized subset of {0, 1, ..., n - 1}.
vector<int> RandomSubset(int n, int k) {
  unordered_map<int, int> changed_elements;
  default_random_engine seed((random_device())());  // Random num generator.
  for (int i = 0; i < k; ++i) {
    // Generate a random index in [i, n - 1].
    int rand_idx = uniform_int_distribution<int>{i, n - 1}(seed);
    if (auto ptr1 = changed_elements.find(rand_idx),
        ptr2 = changed_elements.find(i);
        ptr1 == end(changed_elements) && ptr2 == end(changed_elements)) {
      changed_elements[rand_idx] = i;
      changed_elements[i] = rand_idx;
    } else if (ptr1 == end(changed_elements) && ptr2 != end(changed_elements)) {
      changed_elements[rand_idx] = ptr2->second;
      ptr2->second = rand_idx;
    } else if (ptr1 != end(changed_elements) && ptr2 == end(changed_elements)) {
      changed_elements[i] = ptr1->second;
      ptr1->second = i;
    } else {
      int temp = ptr2->second;
      changed_elements[i] = ptr1->second;
      changed_elements[rand_idx] = temp;
    }
  }

  vector<int> result;
  for (int i = 0; i < k; ++i) {
    result.emplace_back(changed_elements[i]);
  }
  return result;
}

bool RandomSubsetRunner(TimedExecutor& executor, int n, int k) {
  using namespace test_framework;
  vector<vector<int>> results;

  executor.Run([&] {
    std::generate_n(back_inserter(results), 100000,
                    std::bind(RandomSubset, n, k));
  });

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

void RandomSubsetWrapper(TimedExecutor& executor, int n, int k) {
  RunFuncWithRetries(bind(RandomSubsetRunner, std::ref(executor), n, k));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "n", "k"};
  return GenericTestMain(args, "random_subset.cc", "random_subset.tsv",
                         &RandomSubsetWrapper, DefaultComparator{},
                         param_names);
}
