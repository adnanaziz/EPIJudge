#include <algorithm>
#include <iterator>
#include <vector>

#include "test_framework/generic_test.h"

using std::vector;

int SmallestNonconstructibleValue(vector<int> A) {
  sort(begin(A), end(A));
  int max_constructible_value = 0;
  for (int a : A) {
    if (a > max_constructible_value + 1) {
      break;
    }
    max_constructible_value += a;
  }
  return max_constructible_value + 1;
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"A"};
  return GenericTestMain(args, "smallest_nonconstructible_value.cc", "smallest_nonconstructible_value.tsv", &SmallestNonconstructibleValue,
                         DefaultComparator{}, param_names);
}
// clang-format on
