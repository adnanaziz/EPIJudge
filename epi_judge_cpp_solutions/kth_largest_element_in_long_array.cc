#include <algorithm>
#include <functional>
#include <vector>

#include "test_framework/generic_test.h"

using std::greater;
using std::vector;

int FindKthLargestUnknownLength(vector<int>::const_iterator stream_begin,
                                const vector<int>::const_iterator& stream_end,
                                int k) {
  vector<int> candidates;
  while (stream_begin != stream_end) {
    candidates.emplace_back(*stream_begin++);
    if (size(candidates) == 2 * k - 1) {
      // Reorders elements about k-th largest element with larger elements
      // appearing before it.
      nth_element(begin(candidates), begin(candidates) + k - 1, end(candidates),
                  greater<int>());
      // Resize to keep just the k largest elements seen so far.
      candidates.resize(k);
    }
  }
  // Finds the k-th largest element in candidates.
  nth_element(begin(candidates), begin(candidates) + k - 1, end(candidates),
              greater<int>());
  return candidates[k - 1];
}

int FindKthLargestUnknownLengthWrapper(const vector<int>& stream, int k) {
  return FindKthLargestUnknownLength(stream.cbegin(), stream.cend(), k);
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"stream", "k"};
  return GenericTestMain(args, "kth_largest_element_in_long_array.cc", "kth_largest_element_in_long_array.tsv", &FindKthLargestUnknownLengthWrapper,
                         DefaultComparator{}, param_names);
}
// clang-format on
