#include <string>
#include <vector>

using std::string;
using std::vector;

int LevenshteinDistance(const string& A, const string& B) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  GenericTestMain(args, "levenshtein_distance.tsv", &LevenshteinDistance,
                  DefaultComparator{}, param_names);
  return 0;
}
