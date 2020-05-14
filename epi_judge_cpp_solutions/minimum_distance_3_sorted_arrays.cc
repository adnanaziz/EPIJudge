#include <algorithm>
#include <iterator>
#include <limits>
#include <map>
#include <vector>

#include "test_framework/generic_test.h"

using std::min;
using std::multimap;
using std::next;
using std::numeric_limits;
using std::vector;

int FindClosestElementsInSortedArrays(
    const vector<vector<int>>& sorted_arrays) {
  struct IterTail {
    vector<int>::const_iterator iter, tail;
  };
  // Stores two iterators in each entry. One for traversing, and the other to
  // check we reach the end.
  multimap<int, IterTail> iter_and_tail;
  for (const vector<int>& sorted_array : sorted_arrays) {
    iter_and_tail.emplace(sorted_array.front(),
                          IterTail{cbegin(sorted_array), cend(sorted_array)});
  }

  int min_distance_so_far = numeric_limits<int>::max();
  while (true) {
    int min_value = cbegin(iter_and_tail)->first,
        max_value = crbegin(iter_and_tail)->first;
    min_distance_so_far = min(max_value - min_value, min_distance_so_far);
    const auto next_min = next(cbegin(iter_and_tail)->second.iter),
               next_end = cbegin(iter_and_tail)->second.tail;
    // Return if some array has no remaining elements.
    if (next_min == next_end) {
      return min_distance_so_far;
    }
    iter_and_tail.emplace(*next_min, IterTail{next_min, next_end});
    iter_and_tail.erase(cbegin(iter_and_tail));
  }
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"sorted_arrays"};
  return GenericTestMain(args, "minimum_distance_3_sorted_arrays.cc", "minimum_distance_3_sorted_arrays.tsv", &FindClosestElementsInSortedArrays,
                         DefaultComparator{}, param_names);
}
// clang-format on
