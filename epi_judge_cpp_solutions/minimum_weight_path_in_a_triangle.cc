#include <algorithm>
#include <vector>

#include "test_framework/generic_test.h"

using std::min;
using std::vector;

int MinimumPathWeight(const vector<vector<int>>& triangle) {
  if (empty(triangle)) {
    return 0;
  }

  // As we iterate, prev_row stores the minimum path sum to each entry in
  // triangle[i - 1].
  vector<int> prev_row(triangle.front());
  for (int i = 1; i < size(triangle); ++i) {
    // Stores the minimum path sum to each entry in triangle[i].
    vector<int> curr_row(triangle[i]);
    curr_row.front() += prev_row.front();  // For the first element.
    for (int j = 1; j < size(curr_row) - 1; ++j) {
      curr_row[j] += min(prev_row[j - 1], prev_row[j]);
    }
    curr_row.back() += prev_row.back();  // For the last element.

    // Uses swap to assign curr_row's content to prev_row in O(1) time.
    prev_row.swap(curr_row);
  }
  return *min_element(cbegin(prev_row), cend(prev_row));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"triangle"};
  return GenericTestMain(args, "minimum_weight_path_in_a_triangle.cc",
                         "minimum_weight_path_in_a_triangle.tsv",
                         &MinimumPathWeight, DefaultComparator{}, param_names);
}
