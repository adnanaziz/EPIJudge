#include <algorithm>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

#include "test_framework/generic_test.h"

using std::accumulate;
using std::max;
using std::string;
using std::vector;

string Join(const vector<string>&, const string&);

vector<string> JustifyText(const vector<string>& words, int L) {
  int curr_line_length = 0;
  vector<string> result, curr_line;
  for (const string& word : words) {
    if (curr_line_length + size(word) + size(curr_line) > L) {
      for (int i = 0; i < L - curr_line_length; ++i) {
        curr_line[i % max(static_cast<int>(size(curr_line)) - 1, 1)] += ' ';
      }
      result.emplace_back(Join(curr_line, ""));
      curr_line.clear();
      curr_line_length = 0;
    }
    curr_line.emplace_back(word);
    curr_line_length += size(word);
  }
  // Handles the last line. Last line is to be left-aligned.
  result.emplace_back(
      Join(curr_line, " ")
          .append(L - curr_line_length - (size(curr_line) - 1), ' '));
  return result;
}

string Join(const vector<string>& words, const string& delimiter) {
  return accumulate(next(begin(words)), end(words), words.front(),
                    [delimiter](const string& result, const string& word) {
                      return result + delimiter + word;
                    });
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"words", "L"};
  return GenericTestMain(args, "left_right_justify_text.cc",
                         "left_right_justify_text.tsv", &JustifyText,
                         DefaultComparator{}, param_names);
}
