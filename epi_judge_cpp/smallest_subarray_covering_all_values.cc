#include <string>
#include <vector>

#include "test_framework/test_failure_exception.h"
#include "test_framework/test_timer.h"

using std::string;
using std::vector;

struct Subarray {
  // Represent subarray by starting and ending indices, inclusive.
  int start, end;
};

Subarray FindSmallestSequentiallyCoveringSubset(
    const vector<string>& paragraph, const vector<string>& keywords) {
  // Implement this placeholder.
  return {0, 0};
}

int FindSmallestSequentiallyCoveringSubsetWrapper(
    TestTimer& timer, const vector<string>& paragraph,
    const vector<string>& keywords) {
  timer.Start();
  auto result = FindSmallestSequentiallyCoveringSubset(paragraph, keywords);
  timer.Stop();

  int kw_idx = 0;
  if (result.start < 0) {
    throw TestFailureException("Subarray start index is negative");
  }
  int para_idx = result.start;

  while (kw_idx < keywords.size()) {
    if (para_idx >= paragraph.size()) {
      throw TestFailureException(
          "Not all keywords are in the generated subarray");
    }
    if (para_idx >= paragraph.size()) {
      throw TestFailureException("Subarray end index exceeds array size");
    }
    if (paragraph[para_idx] == keywords[kw_idx]) {
      kw_idx++;
    }
    para_idx++;
  }
  return result.end - result.start + 1;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"timer", "paragraph", "keywords"};
  generic_test_main(argc, argv, param_names, "subsequence_cover.tsv",
                    &FindSmallestSequentiallyCoveringSubsetWrapper);
  return 0;
}
