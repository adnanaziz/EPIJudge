#include <string>
#include <vector>
#include <unordered_map>

#include "test_framework/generic_test.h"
using std::string;
using std::vector;

bool CheckAllWords(const string& s, std::unordered_map<string, int>& keywords_to_count, int start, int word_size, int word_count) {
    std::unordered_map<string, int> current_word_frequency;
    for (int i = 0; i < word_count; i++) {
        string str = s.substr(start + i * word_size, word_size);
        auto iter = keywords_to_count.find(str);

        if (iter == keywords_to_count.end()) {
            return false;
        }

        ++current_word_frequency[str];
        if (current_word_frequency[str] > iter->second){
            return false;
        }
    }

    return true;
}

vector<int> FindAllSubstrings(const string& s, const vector<string>& words) {
    vector<int> results;
    std::unordered_map<string, int> keywords_to_count;

    for (const string keyword : words)
        ++keywords_to_count[keyword];

    int word_size = words.front().size();

    for (int i = 0; i + word_size * words.size() <= s.size(); i++){
        if (CheckAllWords(s, keywords_to_count, i, word_size, words.size()))
            results.emplace_back(i);
    
    }

    return results;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s", "words"};
  return GenericTestMain(args, "string_decompositions_into_dictionary_words.cc",
                         "string_decompositions_into_dictionary_words.tsv",
                         &FindAllSubstrings, DefaultComparator{}, param_names);
}
