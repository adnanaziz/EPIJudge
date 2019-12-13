#include <algorithm>
#include <limits>
#include <string>
#include <unordered_map>
#include <vector>

#include "test_framework/generic_test.h"

using std::max;
using std::min;
using std::numeric_limits;
using std::string;
using std::unordered_map;
using std::vector;

int FindNearestRepetition(const vector<string>& paragraph) {
  unordered_map<string, int> word_to_latest_index;
  int nearest_repeated_distance = numeric_limits<int>::max();
  for (int i = 0; i < size(paragraph); ++i) {
    if (auto latest_equal_word = word_to_latest_index.find(paragraph[i]);
        latest_equal_word != end(word_to_latest_index)) {
      nearest_repeated_distance =
          min(nearest_repeated_distance, i - latest_equal_word->second);
    }
    word_to_latest_index[paragraph[i]] = i;
  }
  return nearest_repeated_distance != numeric_limits<int>::max()
             ? nearest_repeated_distance
             : -1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"paragraph"};
  return GenericTestMain(args, "nearest_repeated_entries.cc",
                         "nearest_repeated_entries.tsv", &FindNearestRepetition,
                         DefaultComparator{}, param_names);
}
