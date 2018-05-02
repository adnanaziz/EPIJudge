#include <algorithm>
#include <string>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

using std::vector;

vector<int> GrayCode(int num_bits) {
  if (num_bits == 0) {
    return {0};
  }

  // These implicitly begin with 0 at bit-index (num_bits - 1).
  vector<int> gray_code_num_bits_minus_1 = GrayCode(num_bits - 1);

  // Now, add a 1 at bit-index (num_bits - 1) to all entries in
  // grayCodeNumBitsMinus1.
  int leading_bit_one = 1 << (num_bits - 1);
  // Process in reverse order to achieve reflection of
  // gray_code_num_bits_minus_1.
  for (int i = size(gray_code_num_bits_minus_1) - 1; i >= 0; --i) {
    gray_code_num_bits_minus_1.emplace_back(leading_bit_one |
                                            gray_code_num_bits_minus_1[i]);
  }
  return gray_code_num_bits_minus_1;
}

bool DiffersByOneBit(int x, int y) {
  int bit_difference = x ^ y;
  return bit_difference && !(bit_difference & (bit_difference - 1));
}

void GrayCodeWrapper(TimedExecutor& executor, int num_bits) {
  vector<int> result = executor.Run([&] { return GrayCode(num_bits); });

  int expected_size = (1 << num_bits);
  if (result.size() != expected_size) {
    throw TestFailure("Length mismatch: expected " +
                      std::to_string(expected_size) + ", got " +
                      std::to_string(result.size()));
  }
  for (size_t i = 1; i < result.size(); i++)
    if (!DiffersByOneBit(result[i - 1], result[i])) {
      if (result[i - 1] == result[i]) {
        throw TestFailure("Two adjacent entries are equal");
      } else {
        throw TestFailure("Two adjacent entries differ by more than 1 bit");
      }
    }

  std::sort(begin(result), end(result));
  auto uniq = std::unique(begin(result), end(result));
  if (uniq != end(result)) {
    throw TestFailure("Not all entries are distinct: found " +
                      std::to_string(std::distance(uniq, end(result))) +
                      " duplicates");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "num_bits"};
  return GenericTestMain(args, "gray_code.cc", "gray_code.tsv",
                         &GrayCodeWrapper, DefaultComparator{}, param_names);
}
