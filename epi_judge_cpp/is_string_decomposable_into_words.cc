#include <string>
#include <unordered_set>
#include <vector>
#include "test_framework/generic_test.h"

using std::string;
using std::unordered_set;
using std::vector;

vector<string> DecomposeIntoDictionaryWords(
    const string& domain, const unordered_set<string>& dictionary) {
  // Implement this placeholder.
  return {};
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"domain", "dictionary"};
  return GenericTestMain(args, "is_string_decomposable_into_words.tsv",
                         &DecomposeIntoDictionaryWords, DefaultComparator{},
                         param_names);
}
