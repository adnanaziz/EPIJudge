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

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"string&", "int", "vector<string>*",
                                       "input"};
  generic_test_main(argc, argv, param_names,
                    "enumerate_palindromic_decompositions.tsv",
                    &PalindromeDecompositions, &Comp);
  return 0;
}
