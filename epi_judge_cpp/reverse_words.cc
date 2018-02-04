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

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"timer", "s"};
  GenericTestMain(args, "reverse_words.tsv", &ReverseWordsWrapper,
                  DefaultComparator{}, param_names);
  return 0;
}
