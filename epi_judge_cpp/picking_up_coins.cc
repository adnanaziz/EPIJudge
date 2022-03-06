#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

int CountMaximumRevenue(const vector<int>& coins, int a, int b, 
                        vector<vector<int>>& maximum_revenue_for_range) {
    if(a>b){
        return 0;
    }

    if(maximum_revenue_for_range[a][b] == 0){
        int min_from_a = coins[a] + std::min(CountMaximumRevenue(coins, a+2, b,maximum_revenue_for_range),
                                             CountMaximumRevenue(coins, a + 1, b-1, maximum_revenue_for_range));

        int min_from_b = coins[b] + std::min(CountMaximumRevenue(coins, a + 1, b - 1, maximum_revenue_for_range),
                                             CountMaximumRevenue(coins, a, b - 2, maximum_revenue_for_range));
    
        maximum_revenue_for_range[a][b] = std::max(min_from_a, min_from_b);
    }
    return maximum_revenue_for_range[a][b];
}

int MaximumRevenue(const vector<int>& coins) {
    vector<vector<int>> maximum_revenue_for_range(coins.size(), vector<int>(coins.size(), 0));
    return CountMaximumRevenue(coins, 0, coins.size() - 1, maximum_revenue_for_range);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"coins"};
  return GenericTestMain(args, "picking_up_coins.cc", "picking_up_coins.tsv",
                         &MaximumRevenue, DefaultComparator{}, param_names);
}
