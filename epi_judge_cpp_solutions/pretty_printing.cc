#include <algorithm>
#include <limits>
#include <string>
#include <vector>

#include "test_framework/generic_test.h"

using std::min;
using std::numeric_limits;
using std::string;
using std::vector;

int MinimumMessiness(const vector<string>& words, int line_length) {
  // minimum_messiness[i] is the minimum messiness when placing words[0, i].
  vector<int> minimum_messiness(size(words), numeric_limits<int>::max());
  int num_remaining_blanks = line_length - size(words[0]);
  minimum_messiness[0] = num_remaining_blanks * num_remaining_blanks;
  for (int i = 1; i < size(words); ++i) {
    num_remaining_blanks = line_length - size(words[i]);
    minimum_messiness[i] =
        minimum_messiness[i - 1] + num_remaining_blanks * num_remaining_blanks;
    // Try adding words[i - 1], words[i - 2], ...
    for (int j = i - 1; j >= 0; --j) {
      num_remaining_blanks -= (size(words[j]) + 1);
      if (num_remaining_blanks < 0) {
        // Not enough space to add more words.
        break;
      }
      int first_j_messiness = j - 1 < 0 ? 0 : minimum_messiness[j - 1];
      int current_line_messiness = num_remaining_blanks * num_remaining_blanks;
      minimum_messiness[i] =
          min(minimum_messiness[i], first_j_messiness + current_line_messiness);
    }
  }
  return minimum_messiness.back();
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"words", "line_length"};
  return GenericTestMain(args, "pretty_printing.cc", "pretty_printing.tsv",
                         &MinimumMessiness, DefaultComparator{}, param_names);
}
