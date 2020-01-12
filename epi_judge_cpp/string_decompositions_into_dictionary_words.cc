#include <string>
#include <vector>

#include "test_framework/generic_test.h"
using std::string;
using std::vector;

vector<int> FindAllSubstrings(const string& s, const vector<string>& words) {
  // TODO - you fill in here.
  return {};
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s", "words"};
  return GenericTestMain(args, "string_decompositions_into_dictionary_words.cc",
                         "string_decompositions_into_dictionary_words.tsv",
                         &FindAllSubstrings, DefaultComparator{}, param_names);
}
