#include <string>

using std::string;

bool IsLetterConstructibleFromMagazine(const string& letter_text,
                                       const string& magazine_text) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"letter_text", "magazine_text"};
  GenericTestMain(args, "is_anonymous_letter_constructible.tsv",
                  &IsLetterConstructibleFromMagazine, DefaultComparator{},
                  param_names);
  return 0;
}
