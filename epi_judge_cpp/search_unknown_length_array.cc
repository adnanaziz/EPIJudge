#include <vector>

using std::vector;

int BinarySearchUnknownLength(const vector<int>& A, int k) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "k"};
  GenericTestMain(args, "search_unknown_length_array.tsv",
                  &BinarySearchUnknownLength, DefaultComparator{}, param_names);
  return 0;
}
