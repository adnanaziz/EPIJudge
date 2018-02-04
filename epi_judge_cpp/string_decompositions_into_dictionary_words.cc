#include <string>
#include <vector>

using std::string;
using std::vector;

vector<int> FindAllSubstrings(const string& s, const vector<string>& words) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s", "words"};
  GenericTestMain(args, "string_decompositions_into_dictionary_words.tsv",
                  &FindAllSubstrings, DefaultComparator{}, param_names);
  return 0;
}
