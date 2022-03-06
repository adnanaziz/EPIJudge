#include <string>
#include <vector>

#include "test_framework/generic_test.h"
using std::string;
using std::vector;

string JoinALineWithSpaces(const vector<string>& words, int start, int end, int total_number_spaces) {
    string line;
    int no_of_word = end - start + 1;
    int space_to_add = total_number_spaces;

    for (int i = start; i < end; i++) {
        line += words[i];
        no_of_word -= 1;
        int no_of_spaces = ceil(static_cast<double>(space_to_add) / no_of_word);

        line.append(no_of_spaces, ' ');
        space_to_add -= no_of_spaces;
    }

    line += words[end];
    line.append(space_to_add, ' ');
    return line;
}

vector<string> JustifyText(const vector<string>& words, int L) {
    vector<string> results;
    int no_words_current_line = 0, current_line_start = 0, current_line_len = 0;

    for (int i = 0; i < words.size(); i++) {
        no_words_current_line++;

        int look_forward_len = current_line_len + words[i].size() + (no_words_current_line - 1);
        if (look_forward_len == L) {
            results.emplace_back(JoinALineWithSpaces(words, current_line_start, i, no_words_current_line - 1));
            current_line_start = i + 1, no_words_current_line = 0, current_line_len = 0;
        }
        else if (look_forward_len > L) {
            results.emplace_back(JoinALineWithSpaces(words, current_line_start, i-1, L - current_line_len));
            current_line_start = i, no_words_current_line = 1, current_line_len = words[i].size();
        }
        else {
            current_line_len += words[i].size();
        }
    }

    if (no_words_current_line > 0) {
        string line = JoinALineWithSpaces(words, current_line_start, words.size() - 1, no_words_current_line-1);
        line.append(L - line.size(), ' ');

        results.emplace_back(line);
    }


    return results;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"words", "L"};
  return GenericTestMain(args, "left_right_justify_text.cc",
                         "left_right_justify_text.tsv", &JustifyText,
                         DefaultComparator{}, param_names);
}
