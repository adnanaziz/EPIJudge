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
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"domain", "dictionary"};
  return GenericTestMain(
      args, timeout_seconds, "is_string_decomposable_into_words.tsv",
      &DecomposeIntoDictionaryWords, DefaultComparator{}, param_names);
}
