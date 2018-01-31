#include <string>

#include "test_framework/test_timer.h"

using std::string;

void ReverseWords(string* s) {
  // Implement this placeholder.
  return;
}

string ReverseWordsWrapper(TestTimer& timer, string s) {
  string s_copy = s;
  timer.Start();
  ReverseWords(&s_copy);
  timer.Stop();
  return s_copy;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"timer", "s"};
  generic_test_main(argc, argv, param_names, "reverse_words.tsv",
                    &ReverseWordsWrapper);
  return 0;
}
