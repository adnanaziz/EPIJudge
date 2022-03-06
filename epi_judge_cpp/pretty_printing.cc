#include <string>
#include <vector>

#include "test_framework/generic_test.h"
using std::string;
using std::vector;

int MinimumMessiness(const vector<string>& words, int line_length) {
    vector<int> minimum_messings(words.size(), std::numeric_limits<int>::max());
    int number_of_space_remaining = line_length - words[0].size();
    minimum_messings[0] = number_of_space_remaining * number_of_space_remaining;

    for (int i = 1; i < words.size(); i++) {
        number_of_space_remaining = line_length - words[i].size();
        minimum_messings[i] = number_of_space_remaining * number_of_space_remaining + minimum_messings[i-1];
    
        for (int j = i - 1; j >= 0; j--) {
            number_of_space_remaining -= (words[j].size() + 1);
            if (number_of_space_remaining < 0) {
                break;
            }

            int first_j_space = j - 1 < 0 ? 0 : minimum_messings[j - 1];
            int current_line_messing = number_of_space_remaining * number_of_space_remaining;

            minimum_messings[i] = std::min(minimum_messings[i], current_line_messing+ first_j_space);
        }
    }

    return minimum_messings.back();
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"words", "line_length"};
  return GenericTestMain(args, "pretty_printing.cc", "pretty_printing.tsv",
                         &MinimumMessiness, DefaultComparator{}, param_names);
}
