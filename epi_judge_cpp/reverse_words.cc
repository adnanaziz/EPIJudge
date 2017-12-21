#include <string>

using std::string;

void ReverseWords(string* s) {
  // Implement this placeholder.
  return;
}

string ReverseWordsWrapper(string s) {
  ReverseWords(&s);
  return s;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "reverse_words.tsv", &ReverseWordsWrapper);
  return 0;
}
