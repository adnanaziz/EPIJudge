#include <algorithm>
#include <functional>
#include <unordered_map>
#include <vector>

#include "test_framework/random_sequence_checker.h"
#include "test_framework/test_timer.h"

using std::abs;
using std::bind;
using std::unordered_map;
using std::vector;

int NonuniformRandomNumberGeneration(const vector<int>& values,
                                     const vector<double>& probabilities) {
  // Implement this placeholder.
  return 0;
}

bool NonuniformRandomNumberGenerationRunner(
    TestTimer& timer, const vector<int>& values,
    const vector<double>& probabilities) {
  int n = 1.0e6;
  vector<int> results;
  timer.Start();
  for (int i = 0; i < n; ++i) {
    results.emplace_back(
        NonuniformRandomNumberGeneration(values, probabilities));
  }
  timer.Stop();

  unordered_map<int, int> counts;
  for (int result : results) {
    ++counts[result];
  }
  for (int i = 0; i < values.size(); ++i) {
    const int v = values[i];
    const double p = probabilities[i];
    if (n * p < 50 || n * (1.0 - p) < 50) {
      continue;
    }
    const double sigma = sqrt(n * p * (1.0 - p));
    if (abs(counts[v] - (p * n)) > 5 * sigma) {
      return false;
    }
  }
  return true;
}

void NonuniformRandomNumberGenerationWrapper(
    TestTimer& timer, const vector<int>& values,
    const vector<double>& probabilities) {
  RunFuncWithRetries(bind(NonuniformRandomNumberGenerationRunner, timer, values,
                          probabilities));
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "nonuniform_random_number.tsv",
                    &NonuniformRandomNumberGenerationWrapper);
  return 0;
}
