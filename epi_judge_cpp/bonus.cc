#include <vector>
#include "test_framework/generic_test.h"

using std::vector;

int CalculateBonus(const vector<int>& productivity) {
  // Implement this placeholder.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"productivity"};
  return GenericTestMain(args, "bonus.tsv", &CalculateBonus,
                         DefaultComparator{}, param_names);
}
