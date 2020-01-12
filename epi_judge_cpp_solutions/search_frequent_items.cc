#include <algorithm>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>

#include "test_framework/generic_test.h"

using std::for_each;
using std::string;
using std::unordered_map;
using std::vector;

// Finds the candidates which may occur > n / k times.
vector<string> SearchFrequentItems(
    int k, vector<string>::const_iterator stream_begin,
    const vector<string>::const_iterator stream_end) {
  vector<string>::const_iterator stream_begin_copy = stream_begin;
  unordered_map<string, int> table;
  int n = 0;  // Count the number of strings.

  while (stream_begin != stream_end) {
    ++table[*stream_begin++], ++n;
    // Detecting k items in table, at least one of them must have exactly
    // one in it. We will discard those k items by one for each.
    if (size(table) == k) {
      auto it = begin(table);
      while (it != end(table)) {
        if (--(it->second) == 0) {
          table.erase(it++);
        } else {
          ++it;
        }
      }
    }
  }

  // Resets table for the following counting.
  for_each(begin(table), end(table), [](auto& it) { it.second = 0; });

  // Resets the stream and read it again.
  stream_begin = stream_begin_copy;
  // Counts the occurrence of each candidate word.
  while (stream_begin != stream_end) {
    if (auto it = table.find(*stream_begin++); it != end(table)) {
      ++it->second;
    }
  }

  // Selects the word which occurs > n / k times.
  vector<string> result;
  for_each(begin(table), end(table), [&](const auto& it) {
    if (it.second > static_cast<double>(n) / k) {
      result.emplace_back(it.first);
    }
  });
  return result;
}

vector<string> SearchFrequentItemsWrapper(int k, vector<string>& stream) {
  return SearchFrequentItems(k, begin(stream), end(stream));
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"k", "stream"};
  return GenericTestMain(args, "search_frequent_items.cc", "search_frequent_items.tsv", &SearchFrequentItemsWrapper,
                         UnorderedComparator{}, param_names);
}
// clang-format on
