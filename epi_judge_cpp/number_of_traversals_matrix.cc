#include <vector>
#include "test_framework/generic_test.h"

using std::vector;

int ComputeNumOfWays(int n, int m, vector<vector<int>>& number_of_ways) {
    if (n == 0 && m == 0)
        return 1;

    if (number_of_ways[n][m] == 0) {
        int left_move = m > 0 ? ComputeNumOfWays(n, m - 1, number_of_ways) : 0;
        int up_move = n > 0 ? ComputeNumOfWays(n - 1, m, number_of_ways) : 0;

        number_of_ways[n][m] = left_move + up_move;
    }
    return number_of_ways[n][m];
}

int NumberOfWays(int n, int m) {
    vector<vector<int>> number_of_ways(n, vector<int>(m, 0));
    return ComputeNumOfWays(n-1, m-1, number_of_ways);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n", "m"};
  return GenericTestMain(args, "number_of_traversals_matrix.cc",
                         "number_of_traversals_matrix.tsv", &NumberOfWays,
                         DefaultComparator{}, param_names);
}
