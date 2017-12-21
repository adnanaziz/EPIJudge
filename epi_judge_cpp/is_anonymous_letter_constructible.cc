#include <string>

using std::string;

bool IsLetterConstructibleFromMagazine(const string& letter_text,
                                       const string& magazine_text) {
  // Implement this placeholder.
  return true;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "is_anonymous_letter_constructible.tsv",
                    &IsLetterConstructibleFromMagazine);
  return 0;
}
