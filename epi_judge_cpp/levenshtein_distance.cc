#include <string>
#include <vector>
#include "test_framework/generic_test.h"

using std::string;
using std::vector;

int LevenshteinDistance(const string& A, const string& B) {
  // Implement this placeholder.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(args, "levenshtein_distance.tsv", &LevenshteinDistance,
                         DefaultComparator{}, param_names);
}
