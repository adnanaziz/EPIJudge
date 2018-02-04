#include <algorithm>
#include <string>
#include <vector>

#include "test_framework/test_failure_exception.h"
#include "test_framework/test_timer.h"

using std::vector;

vector<int> GrayCode(int num_bits) {
  // Implement this placeholder.
  return {};
}

bool DiffersByOneBit(int x, int y) {
  int bit_difference = x ^ y;
  return bit_difference && !(bit_difference & (bit_difference - 1));
}

void GrayCodeWrapper(TestTimer& timer, int num_bits) {
  timer.Start();
  vector<int> result = GrayCode(num_bits);
  timer.Stop();

  int expected_size = (1 << num_bits);
  if (result.size() != expected_size) {
    throw TestFailureException("Length mismatch: expected " +
                               std::to_string(expected_size) + ", got " +
                               std::to_string(result.size()));
  }
  for (size_t i = 1; i < result.size(); i++)
    if (!DiffersByOneBit(result[i - 1], result[i])) {
      if (result[i - 1] == result[i]) {
        throw TestFailureException("Two adjacent entries are equal");
      } else {
        throw TestFailureException(
            "Two adjacent entries differ by more than 1 bit");
      }
    }

  std::sort(begin(result), end(result));
  auto uniq = std::unique(begin(result), end(result));
  if (uniq != end(result)) {
    throw TestFailureException(
        "Not all entries are distinct: found " +
        std::to_string(std::distance(uniq, end(result))) + " duplicates");
  }
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"timer", "num_bits"};
  GenericTestMain(args, "gray_code.tsv", &GrayCodeWrapper, DefaultComparator{},
                  param_names);
  return 0;
}
