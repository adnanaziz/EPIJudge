#include <memory>
#include <vector>

#include "test_framework/generic_test.h"

using std::make_unique;
using std::vector;

void DirectedCombinations(int, int, int, vector<int>*, vector<vector<int>>*);

vector<vector<int>> Combinations(int n, int k) {
  vector<vector<int>> result;
  DirectedCombinations(n, k, 1, make_unique<vector<int>>().get(), &result);
  return result;
}

void DirectedCombinations(int n, int k, int offset,
                          vector<int>* partial_combination,
                          vector<vector<int>>* result) {
  if (size(*partial_combination) == k) {
    result->emplace_back(*partial_combination);
    return;
  }

  // Generate remaining combinations over {offset, ..., n - 1} of size
  // num_remaining.
  const int num_remaining = k - size(*partial_combination);
  for (int i = offset; i <= n && num_remaining <= n - i + 1; ++i) {
    partial_combination->emplace_back(i);
    DirectedCombinations(n, k, i + 1, partial_combination, result);
    partial_combination->pop_back();
  }
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"n", "k"};
  return GenericTestMain(args, "combinations.cc", "combinations.tsv", &Combinations,
                         UnorderedComparator{}, param_names);
}
// clang-format on
