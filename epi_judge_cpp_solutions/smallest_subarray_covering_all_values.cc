#include <limits>
#include <string>
#include <unordered_map>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

using std::numeric_limits;
using std::string;
using std::unordered_map;
using std::vector;

struct Subarray {
  // Represent subarray by starting and ending indices, inclusive.
  int start, end;
};

Subarray FindSmallestSequentiallyCoveringSubset(
    const vector<string>& paragraph, const vector<string>& keywords) {
  // Maps each keyword to its index in the keywords array.
  unordered_map<string, int> keyword_to_idx;
  // Initializes keyword_to_idx.
  for (int i = 0; i < size(keywords); ++i) {
    keyword_to_idx.emplace(keywords[i], i);
  }

  // Since keywords are uniquely identified by their indices in keywords
  // array, we can use those indices as keys to lookup in a vector.
  vector<int> latest_occurrence(size(keywords), -1);
  // For each keyword (identified by its index in keywords array), storesult
  // the length of the shortest subarray ending at the most recent occurrence
  // of that keyword that sequentially cover all keywords up to that keyword.
  vector<int> shortest_subarray_length(size(keywords),
                                       numeric_limits<int>::max());

  int shortest_distance = numeric_limits<int>::max();
  Subarray result = Subarray{-1, -1};
  for (int i = 0; i < size(paragraph); ++i) {
    if (keyword_to_idx.count(paragraph[i])) {
      int keyword_idx = keyword_to_idx.find(paragraph[i])->second;
      if (keyword_idx == 0) {  // First keyword.
        shortest_subarray_length[keyword_idx] = 1;
      } else if (shortest_subarray_length[keyword_idx - 1] !=
                 numeric_limits<int>::max()) {
        int distance_to_previous_keyword =
            i - latest_occurrence[keyword_idx - 1];
        shortest_subarray_length[keyword_idx] =
            distance_to_previous_keyword +
            shortest_subarray_length[keyword_idx - 1];
      }
      latest_occurrence[keyword_idx] = i;

      // Last keyword, look for improved subarray.
      if (keyword_idx == size(keywords) - 1 &&
          shortest_subarray_length.back() < shortest_distance) {
        shortest_distance = shortest_subarray_length.back();
        result = {i - shortest_subarray_length.back() + 1, i};
      }
    }
  }
  return result;
}

int FindSmallestSequentiallyCoveringSubsetWrapper(
    TimedExecutor& executor, const vector<string>& paragraph,
    const vector<string>& keywords) {
  auto result = executor.Run([&] {
    return FindSmallestSequentiallyCoveringSubset(paragraph, keywords);
  });

  int kw_idx = 0;
  if (result.start < 0) {
    throw TestFailure("Subarray start index is negative");
  }
  int para_idx = result.start;

  while (kw_idx < keywords.size()) {
    if (para_idx >= paragraph.size()) {
      throw TestFailure("Not all keywords are in the generated subarray");
    }
    if (para_idx >= paragraph.size()) {
      throw TestFailure("Subarray end index exceeds array size");
    }
    if (paragraph[para_idx] == keywords[kw_idx]) {
      kw_idx++;
    }
    para_idx++;
  }
  return result.end - result.start + 1;
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"executor", "paragraph", "keywords"};
  return GenericTestMain(args, "smallest_subarray_covering_all_values.cc", "smallest_subarray_covering_all_values.tsv", &FindSmallestSequentiallyCoveringSubsetWrapper,
                         DefaultComparator{}, param_names);
}
// clang-format on
