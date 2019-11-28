#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

#include "test_framework/generic_test.h"

using std::string;
using std::unordered_map;
using std::vector;

vector<vector<string>> FindAnagrams(const vector<string>& dictionary) {
  unordered_map<string, vector<string>> sorted_string_to_anagrams;
  for (const string& s : dictionary) {
    // Sorts the string, uses it as a key, and then appends
    // the original string as another value into hash table.
    string sorted_str(s);
    sort(begin(sorted_str), end(sorted_str));
    sorted_string_to_anagrams[sorted_str].emplace_back(s);
  }

  vector<vector<string>> anagram_groups;
  for (const auto& [key, group] : sorted_string_to_anagrams) {
    if (size(group) >= 2) {  // Found anagrams.
      anagram_groups.emplace_back(group);
    }
  }
  return anagram_groups;
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"dictionary"};
  return GenericTestMain(args, "anagrams.cc", "anagrams.tsv", &FindAnagrams,
                         UnorderedComparator{}, param_names);
}
// clang-format on
