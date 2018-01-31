#include <string>
#include <vector>

using std::string;
using std::vector;

vector<int> FindAllSubstrings(const string& s, const vector<string>& words) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"s", "words"};
  generic_test_main(argc, argv, param_names,
                    "string_decompositions_into_dictionary_words.tsv",
                    &FindAllSubstrings);
  return 0;
}
