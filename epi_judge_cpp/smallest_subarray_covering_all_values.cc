#include <string>
#include <vector>
#include <unordered_map>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::string;
using std::vector;


struct Subarray {
  // Represent subarray by starting and ending indices, inclusive.
  int start, end;
};

Subarray FindSmallestSequentiallyCoveringSubset(
    const vector<string>& paragraph, const vector<string>& keywords) {
    Subarray result = {-1, -1};

    std::unordered_map<string, int> keywords_to_index;
    for (int i = 0; i < keywords.size(); i++) {
        keywords_to_index.emplace(keywords[i], i);
    }

    vector<int> latest_occurance(keywords.size(), -1);
    vector<int> shortest_path(keywords.size(), std::numeric_limits<int>::max());

    int shortest_path_len = std::numeric_limits<int>::max();

    for (int i = 0; i < paragraph.size(); i++) {
        string text = paragraph[i];
        if (keywords_to_index.count(text)) {
            int indx = keywords_to_index[text];
            if (indx == 0) {
                shortest_path[indx] = 1;
            }
            else if (shortest_path[indx - 1] < std::numeric_limits<int>::max()) {
                int distance_from_prev_key = i - latest_occurance[indx - 1];
                shortest_path[indx] = distance_from_prev_key + shortest_path[indx -1];
            }
            latest_occurance[indx] = i;
        
            if (indx == keywords.size() - 1 && shortest_path_len > shortest_path.back()) {
                shortest_path_len = shortest_path.back();
                result = { i - shortest_path.back() +1, i };
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

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "paragraph", "keywords"};
  return GenericTestMain(args, "smallest_subarray_covering_all_values.cc",
                         "smallest_subarray_covering_all_values.tsv",
                         &FindSmallestSequentiallyCoveringSubsetWrapper,
                         DefaultComparator{}, param_names);
}
