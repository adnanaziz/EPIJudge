#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

int MinimumPathWeight(const vector<vector<int>>& triangle) {
    if (triangle.empty())
        return 0;

    vector<int> prev_row(triangle.front());
    for (int i = 1; i < triangle.size(); i++) {
        vector<int> curr_row(triangle[i]);
        
        curr_row.front() += prev_row.front();
        
        for (int j = 1; j < curr_row.size() - 1; j++) {
            curr_row[j] += std::min(prev_row[j-1], prev_row[j]);
        }
        curr_row.back() += prev_row.back();

        prev_row.swap(curr_row);
    }

    return *std::min_element(prev_row.cbegin(), prev_row.cend());
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"triangle"};
  return GenericTestMain(args, "minimum_weight_path_in_a_triangle.cc",
                         "minimum_weight_path_in_a_triangle.tsv",
                         &MinimumPathWeight, DefaultComparator{}, param_names);
}
