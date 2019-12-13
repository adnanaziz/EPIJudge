#include <algorithm>
#include <iterator>
#include <string>
#include <unordered_set>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

using std::string;
using std::unordered_set;
using std::vector;

vector<string> DecomposeIntoDictionaryWords(
    const string& domain, const unordered_set<string>& dictionary) {
  // When the algorithm finishes, last_length[i] != -1 indicates
  // domain.substr(0, i + 1) has a valid decomposition, and the length of the
  // last string in the decomposition is last_length[i].
  vector<int> last_length(size(domain), -1);
  for (int i = 0; i < size(domain); ++i) {
    // If domain.substr(0, i + 1) is a dictionary word, set last_length[i] to
    // the length of that word.
    if (dictionary.count(domain.substr(0, i + 1))) {
      last_length[i] = i + 1;
      continue;
    }

    // If domain.substr(0, i + 1) is not a dictionary word, we look for j < i
    // such that domain.substr(0, j + 1) has a valid decomposition and
    // domain.substring(j + 1, i + 1) is a dictionary word. If so, record the
    // length of that word in last_length[i].
    for (int j = 0; j < i; ++j) {
      if (last_length[j] != -1 &&
          dictionary.count(domain.substr(j + 1, i - j))) {
        last_length[i] = i - j;
        break;
      }
    }
  }

  vector<string> decompositions;
  if (last_length.back() != -1) {
    // domain can be assembled by dictionary words.
    int idx = size(domain) - 1;
    while (idx >= 0) {
      decompositions.emplace_back(
          domain.substr(idx + 1 - last_length[idx], last_length[idx]));
      idx -= last_length[idx];
    }
    reverse(begin(decompositions), end(decompositions));
  }
  return decompositions;
}

void DecomposeIntoDictionaryWordsWrapper(
    TimedExecutor& executor, const string& domain,
    const unordered_set<string>& dictionary, bool decomposable) {
  vector<string> result = executor.Run(
      [&] { return DecomposeIntoDictionaryWords(domain, dictionary); });
  if (!decomposable) {
    if (!result.empty()) {
      throw TestFailure("domain is not decomposable");
    }
    return;
  }

  if (std::any_of(std::begin(result), std::end(result),
                  [&](const std::string& s) { return !dictionary.count(s); })) {
    throw TestFailure("Result uses words not in dictionary");
  }

  if (std::accumulate(std::begin(result), std::end(result), string()) !=
      domain) {
    throw TestFailure("Result is not composed into domain");
  }
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"executor", "domain", "dictionary", "decomposable"};
  return GenericTestMain(args, "is_string_decomposable_into_words.cc", "is_string_decomposable_into_words.tsv", &DecomposeIntoDictionaryWordsWrapper,
                         DefaultComparator{}, param_names);
}
// clang-format on
