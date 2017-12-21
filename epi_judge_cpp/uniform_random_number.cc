#include <functional>
#include <random>
#include <vector>

#include "test_framework/random_sequence_checker.h"
#include "test_framework/test_timer.h"

using std::bind;
using std::default_random_engine;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;

int ZeroOneRandom() {
  default_random_engine gen((random_device())());
  uniform_int_distribution<int> dis(0, 1);
  return dis(gen);
}

int UniformRandom(int lower_bound, int upper_bound) {
  // Implement this placeholder.
  return 0;
}

bool UniformRandomRunner(TestTimer& timer, int lower_bound, int upper_bound) {
  vector<int> result;
  timer.Start();
  std::generate_n(back_inserter(result), 100000,
                  std::bind(UniformRandom, lower_bound, upper_bound));
  timer.Stop();

  vector<int> sequence;
  std::transform(begin(result), end(result), back_inserter(sequence),
                 [lower_bound](int result) { return result - lower_bound; });
  return CheckSequenceIsUniformlyRandom(result, upper_bound - lower_bound + 1,
                                        0.01);
}

void UniformRandomWrapper(TestTimer& timer, int lower_bound, int upper_bound) {
  RunFuncWithRetries(
      bind(UniformRandomRunner, timer, lower_bound, upper_bound));
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "uniform_random_number.tsv",
                    &UniformRandomWrapper);
  return 0;
}
