#include <string>
#include <unordered_map>

#include "test_framework/generic_test.h"
using std::string;

bool IsLetterConstructibleFromMagazine(const string& letter_text,
                                       const string& magazine_text) {
    std::unordered_map<char, int> letter_char_frequency;
    for (char c : letter_text) {
        ++letter_char_frequency[c];
    }

    for (char c : magazine_text) {
        const auto& iter = letter_char_frequency.find(c);
        if (iter != letter_char_frequency.cend()) {
            --iter->second;
            if (iter->second == 0) {
                letter_char_frequency.erase(iter);
                if (letter_char_frequency.empty())
                    break;
            }
        }
    
    }

    return letter_char_frequency.empty();
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"letter_text", "magazine_text"};
  return GenericTestMain(args, "is_anonymous_letter_constructible.cc",
                         "is_anonymous_letter_constructible.tsv",
                         &IsLetterConstructibleFromMagazine,
                         DefaultComparator{}, param_names);
}
