#include <string>

using std::string;

bool IsLetterConstructibleFromMagazine(const string& letter_text,
                                       const string& magazine_text) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"letter_text", "magazine_text"};
  generic_test_main(argc, argv, param_names,
                    "is_anonymous_letter_constructible.tsv",
                    &IsLetterConstructibleFromMagazine);
  return 0;
}
