#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

int FindElementAppearsOnce(const vector<int>& A) {
  // TODO - you fill in here.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "element_appearing_once.cc",
                         "element_appearing_once.tsv", &FindElementAppearsOnce,
                         DefaultComparator{}, param_names);
}
