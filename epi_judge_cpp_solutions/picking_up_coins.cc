#include <algorithm>
#include <iterator>
#include <memory>
#include <numeric>
#include <vector>

#include "test_framework/generic_test.h"

using std::make_unique;
using std::max;
using std::min;
using std::partial_sum;
using std::vector;

int ComputeMaximumRevenueForRange(const vector<int>&, int, int,
                                  vector<vector<int>>*);

int MaximumRevenue(const vector<int>& coins) {
  vector<vector<int>> maximum_revenue_for_range(size(coins),
                                                vector<int>(size(coins), 0));
  return ComputeMaximumRevenueForRange(
      coins, 0, size(coins) - 1,
      make_unique<vector<vector<int>>>(size(coins), vector<int>(size(coins), 0))
          .get());
}

int ComputeMaximumRevenueForRange(
    const vector<int>& coins, int a, int b,
    vector<vector<int>>* maximum_revenue_for_range_ptr) {
  if (a > b) {
    // No coins left.
    return 0;
  }

  vector<vector<int>>& maximum_revenue_for_range =
      *maximum_revenue_for_range_ptr;
  if (maximum_revenue_for_range[a][b] == 0) {
    int max_revenue_a =
        coins[a] + min(ComputeMaximumRevenueForRange(
                           coins, a + 2, b, maximum_revenue_for_range_ptr),
                       ComputeMaximumRevenueForRange(
                           coins, a + 1, b - 1, maximum_revenue_for_range_ptr));
    int max_revenue_b =
        coins[b] + min(ComputeMaximumRevenueForRange(
                           coins, a + 1, b - 1, maximum_revenue_for_range_ptr),
                       ComputeMaximumRevenueForRange(
                           coins, a, b - 2, maximum_revenue_for_range_ptr));
    maximum_revenue_for_range[a][b] = max(max_revenue_a, max_revenue_b);
  }
  return maximum_revenue_for_range[a][b];
}

int MaximumRevenueAlternativeHelper(
    const vector<int>& coins, int a, int b, const vector<int>& prefix_sum,
    vector<vector<int>>* maximum_revenue_for_range_ptr) {
  if (a > b) {
    return 0;
  } else if (a == b) {
    return coins[a];
  }

  vector<vector<int>>& maximum_revenue_for_range =
      *maximum_revenue_for_range_ptr;
  if (maximum_revenue_for_range[a][b] == -1) {
    maximum_revenue_for_range[a][b] =
        max(coins[a] + prefix_sum[b] - (a + 1 > 0 ? prefix_sum[a] : 0) -
                MaximumRevenueAlternativeHelper(coins, a + 1, b, prefix_sum,
                                                maximum_revenue_for_range_ptr),
            coins[b] + prefix_sum[b - 1] - (a > 0 ? prefix_sum[a - 1] : 0) -
                MaximumRevenueAlternativeHelper(coins, a, b - 1, prefix_sum,
                                                maximum_revenue_for_range_ptr));
  }
  return maximum_revenue_for_range[a][b];
}

int MaximumRevenueAlternative(const vector<int>& coins) {
  vector<int> prefix_sum;
  partial_sum(begin(coins), end(coins), back_inserter(prefix_sum));
  vector<vector<int>> maximum_revenue_for_range(size(coins),
                                                vector<int>(size(coins), -1));
  return MaximumRevenueAlternativeHelper(
      coins, 0, size(coins) - 1, prefix_sum,
      make_unique<vector<vector<int>>>(size(coins),
                                       vector<int>(size(coins), -1))
          .get());
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"coins"};
  return GenericTestMain(args, "picking_up_coins.cc", "picking_up_coins.tsv",
                         &MaximumRevenue, DefaultComparator{}, param_names);
}
