#include <algorithm>
#include <unordered_map>
#include <vector>

#include "test_framework/generic_test.h"

using std::max;
using std::unordered_map;
using std::vector;

int LongestSubarrayWithDistinctEntries(const vector<int>& A) {
  // Records the most recent occurrences of each entry.
  unordered_map<int, size_t> most_recent_occurrence;
  size_t longest_dup_free_subarray_start_idx = 0, result = 0;
  for (size_t i = 0; i < size(A); ++i) {
    const auto& [inserted_entry, inserted_happen] =
        most_recent_occurrence.emplace(A[i], i);
    // Defer updating dup_idx until we see a duplicate.
    if (!inserted_happen) {
      // A[i] appeared before. Did it appear in the longest current subarray?
      if (inserted_entry->second >= longest_dup_free_subarray_start_idx) {
        result = max(result, i - longest_dup_free_subarray_start_idx);
        longest_dup_free_subarray_start_idx = inserted_entry->second + 1;
      }
      inserted_entry->second = i;
    }
  }
  return max(result, size(A) - longest_dup_free_subarray_start_idx);
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"A"};
  return GenericTestMain(args, "longest_subarray_with_distinct_values.cc", "longest_subarray_with_distinct_values.tsv", &LongestSubarrayWithDistinctEntries,
                         DefaultComparator{}, param_names);
}
// clang-format on
