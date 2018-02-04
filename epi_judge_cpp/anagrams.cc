#include <string>
#include <vector>

using std::string;
using std::vector;

vector<vector<string>> FindAnagrams(const vector<string>& dictionary) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"dictionary"};
  GenericTestMain(args, "anagrams.tsv", &FindAnagrams,
                  &UnorderedComparator<std::vector<std::vector<std::string>>>,
                  param_names);
  return 0;
}
