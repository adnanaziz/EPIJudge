#include <vector>

using std::vector;

vector<int> NextPermutation(vector<int> perm) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"perm"};
  GenericTestMain(args, "next_permutation.tsv", &NextPermutation,
                  DefaultComparator{}, param_names);
  return 0;
}
