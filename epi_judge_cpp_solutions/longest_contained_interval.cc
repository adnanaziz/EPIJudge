#include <algorithm>
#include <iterator>
#include <unordered_set>
#include <vector>

#include "test_framework/generic_test.h"

using std::max;
using std::unordered_set;
using std::vector;

int LongestContainedRange(const vector<int>& A) {
  // unprocessed_entries records the existence of each entry in A.
  unordered_set<int> unprocessed_entries(begin(A), end(A));

  int max_interval_size = 0;
  while (!empty(unprocessed_entries)) {
    int a = *begin(unprocessed_entries);
    unprocessed_entries.erase(a);

    // Finds the lower bound of the largest range containing a.
    int lower_bound = a - 1;
    while (unprocessed_entries.count(lower_bound)) {
      unprocessed_entries.erase(lower_bound);
      --lower_bound;
    }

    // Finds the upper bound of the largest range containing a.
    int upper_bound = a + 1;
    while (unprocessed_entries.count(upper_bound)) {
      unprocessed_entries.erase(upper_bound);
      ++upper_bound;
    }

    max_interval_size = max(max_interval_size, upper_bound - lower_bound - 1);
  }
  return max_interval_size;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(
      args, "longest_contained_interval.cc", "longest_contained_interval.tsv",
      &LongestContainedRange, DefaultComparator{}, param_names);
}
