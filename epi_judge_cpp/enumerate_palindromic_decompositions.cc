#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

using std::string;
using std::vector;

vector<vector<string>> PalindromeDecompositions(const string& input) {
  // Implement this placeholder.
  return {};
}

bool Comp(vector<vector<string>> expected, vector<vector<string>> result) {
  std::sort(begin(expected), end(expected));
  std::sort(begin(result), end(result));
  return expected == result;
};

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"input"};
  GenericTestMain(args, "enumerate_palindromic_decompositions.tsv",
                  &PalindromeDecompositions, &Comp, param_names);
  return 0;
}
