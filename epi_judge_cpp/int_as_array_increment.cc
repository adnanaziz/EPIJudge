#include <vector>

using std::vector;

vector<int> PlusOne(vector<int> A) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  GenericTestMain(args, "int_as_array_increment.tsv", &PlusOne,
                  DefaultComparator{}, param_names);
  return 0;
}
