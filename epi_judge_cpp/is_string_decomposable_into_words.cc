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
    vector<int> last_len(domain.size(), -1);

    for (int i = 0; i < domain.size(); i++) {

        if (dictionary.find(domain.substr(0, i+1)) != dictionary.cend())
        {
            last_len[i] = i + 1;
        }

        if (last_len[i] == -1) {
            for (int j = 0; j < i; j++) {
                if (last_len[j] != -1 && dictionary.find(domain.substr(j+1, i- j)) != dictionary.cend()) {
                    last_len[i] = i - j;
                    break;
                }
            }
        }
    }


    vector<string> decomposition;
    if (last_len[domain.size() - 1] != -1) {
        int idx = domain.size() - 1;
        
        while (idx>=0) {
            decomposition.emplace_back(domain.substr(idx - last_len[idx]+1, last_len[idx]));
            idx -= last_len[idx];
        }
        std::reverse(decomposition.begin(), decomposition.end());
    }
    
    return decomposition;
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

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "domain", "dictionary",
                                       "decomposable"};
  return GenericTestMain(args, "is_string_decomposable_into_words.cc",
                         "is_string_decomposable_into_words.tsv",
                         &DecomposeIntoDictionaryWordsWrapper,
                         DefaultComparator{}, param_names);
}
