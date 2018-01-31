#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_set;
using std::vector;

vector<string> DecomposeIntoDictionaryWords(
    const string& domain, const unordered_set<string>& dictionary) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"domain", "dictionary"};
  generic_test_main(argc, argv, param_names,
                    "is_string_decomposable_into_words.tsv",
                    &DecomposeIntoDictionaryWords);
  return 0;
}
