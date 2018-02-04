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

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"domain", "dictionary"};
  GenericTestMain(args, "is_string_decomposable_into_words.tsv",
                  &DecomposeIntoDictionaryWords, DefaultComparator{},
                  param_names);
  return 0;
}
