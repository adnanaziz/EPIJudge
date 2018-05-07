#include <deque>
#include <vector>
#include "test_framework/generic_test.h"
using std::deque;
using std::vector;

int MaxRectangleSubmatrix(const vector<deque<bool>>& A) {
  // TODO - you fill in here.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "max_submatrix.cc", "max_submatrix.tsv",
                         &MaxRectangleSubmatrix, DefaultComparator{},
                         param_names);
}
