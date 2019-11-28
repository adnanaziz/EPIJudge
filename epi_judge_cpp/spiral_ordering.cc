#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> MatrixInSpiralOrder(const vector<vector<int>>& square_matrix) {
  // TODO - you fill in here.
  return {};
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"square_matrix"};
  return GenericTestMain(args, "spiral_ordering.cc", "spiral_ordering.tsv",
                         &MatrixInSpiralOrder, DefaultComparator{},
                         param_names);
}
