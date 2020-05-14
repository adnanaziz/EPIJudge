#include <algorithm>
#include <memory>
#include <vector>

#include "test_framework/generic_test.h"

using std::make_unique;
using std::swap;
using std::vector;

int ComputeNumberOfWaysToXY(int, int, vector<vector<int>>*);

int NumberOfWays(int n, int m) {
  return ComputeNumberOfWaysToXY(
      n - 1, m - 1,
      make_unique<vector<vector<int>>>(n, vector<int>(m, 0)).get());
}

int ComputeNumberOfWaysToXY(int x, int y,
                            vector<vector<int>>* number_of_ways_ptr) {
  if (x == 0 && y == 0) {
    return 1;
  }

  vector<vector<int>>& number_of_ways = *number_of_ways_ptr;
  if (number_of_ways[x][y] == 0) {
    int ways_top =
        x == 0 ? 0 : ComputeNumberOfWaysToXY(x - 1, y, number_of_ways_ptr);
    int ways_left =
        y == 0 ? 0 : ComputeNumberOfWaysToXY(x, y - 1, number_of_ways_ptr);
    number_of_ways[x][y] = ways_top + ways_left;
  }
  return number_of_ways[x][y];
}

int NumberOfWaysSpaceEfficient(int n, int m) {
  if (n < m) {
    swap(n, m);
  }

  vector<int> table(m, 1);
  for (int i = 1; i < n; ++i) {
    int prev_res = 0;
    if (n < m) {
      swap(n, m);
    }
    for (int j = 0; j < m; ++j) {
      table[j] = table[j] + prev_res;
      prev_res = table[j];
    }
  }
  return table[m - 1];
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n", "m"};
  return GenericTestMain(args, "number_of_traversals_matrix.cc",
                         "number_of_traversals_matrix.tsv", &NumberOfWays,
                         DefaultComparator{}, param_names);
}
