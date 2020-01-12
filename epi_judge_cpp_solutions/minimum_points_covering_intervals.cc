#include <algorithm>
#include <iterator>
#include <limits>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"

using std::numeric_limits;
using std::vector;

struct Interval;

struct Interval {
  int left, right;
};

int FindMinimumVisits(vector<Interval> intervals) {
  // Sort intervals based on the right endpoints.
  sort(begin(intervals), end(intervals),
       [](const Interval& a, const Interval& b) { return a.right < b.right; });
  int last_visit_time = numeric_limits<int>::min(), num_visits = 0;
  for (const Interval& interval : intervals) {
    if (interval.left > last_visit_time) {
      // The current right endpoint, last_visit_time, will not cover any more
      // intervals.
      last_visit_time = interval.right;
      ++num_visits;
    }
  }
  return num_visits;
}

namespace test_framework {
template <>
struct SerializationTrait<Interval> : UserSerTrait<Interval, int, int> {};
}  // namespace test_framework

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"intervals"};
  return GenericTestMain(args, "minimum_points_covering_intervals.cc",
                         "minimum_points_covering_intervals.tsv",
                         &FindMinimumVisits, DefaultComparator{}, param_names);
}
