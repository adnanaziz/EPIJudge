#include <string>
#include <unordered_map>
#include <vector>

#include "test_framework/generic_test.h"

using std::string;
using std::unordered_map;
using std::vector;

bool MatchAllWordsInDict(const string&, const unordered_map<string, int>&, int,
                         int, int);

vector<int> FindAllSubstrings(const string& s, const vector<string>& words) {
  unordered_map<string, int> word_to_freq;
  for (const string& word : words) {
    ++word_to_freq[word];
  }

  int unit_size = size(words.front());
  vector<int> result;
  for (int i = 0; i + unit_size * size(words) <= size(s); ++i) {
    if (MatchAllWordsInDict(s, word_to_freq, i, size(words), unit_size)) {
      result.emplace_back(i);
    }
  }
  return result;
}

bool MatchAllWordsInDict(const string& s,
                         const unordered_map<string, int>& word_to_freq,
                         int start, int num_words, int unit_size) {
  unordered_map<string, int> curr_string_to_freq;
  for (int i = 0; i < num_words; ++i) {
    string curr_word = s.substr(start + i * unit_size, unit_size);
    if (auto iter = word_to_freq.find(curr_word); iter == end(word_to_freq)) {
      return false;
    } else {
      ++curr_string_to_freq[curr_word];
      if (curr_string_to_freq[curr_word] > iter->second) {
        // curr_word occurs too many times for a match to be possible.
        return false;
      }
    }
  }
  return true;
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"s", "words"};
  return GenericTestMain(args, "string_decompositions_into_dictionary_words.cc", "string_decompositions_into_dictionary_words.tsv", &FindAllSubstrings,
                         DefaultComparator{}, param_names);
}
// clang-format on
