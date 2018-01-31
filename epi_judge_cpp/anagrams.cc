#include <string>
#include <vector>

using std::string;
using std::vector;

vector<vector<string>> FindAnagrams(const vector<string>& dictionary) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"dictionary"};
  generic_test_main(
      argc, argv, param_names, "anagrams.tsv", &FindAnagrams,
      &UnorderedComparator<std::vector<std::vector<std::string>>>);
  return 0;
}
