#include <string>
#include <vector>

#include "test_framework/generic_test.h"
using std::string;
using std::vector;

vector<vector<string>> FindAnagrams(const vector<string>& dictionary) {
  // TODO - you fill in here.
  return {};
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"dictionary"};
  return GenericTestMain(args, "anagrams.cc", "anagrams.tsv", &FindAnagrams,
                         UnorderedComparator{}, param_names);
}
