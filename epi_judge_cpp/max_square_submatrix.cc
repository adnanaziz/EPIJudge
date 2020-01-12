#include <deque>
#include <vector>

#include "test_framework/generic_test.h"
using std::deque;
using std::vector;

int MaxSquareSubmatrix(const vector<deque<bool>>& A) {
  // TODO - you fill in here.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "max_square_submatrix.cc",
                         "max_square_submatrix.tsv", &MaxSquareSubmatrix,
                         DefaultComparator{}, param_names);
}
