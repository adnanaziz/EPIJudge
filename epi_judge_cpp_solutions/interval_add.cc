#include <algorithm>
#include <vector>

#include "test_framework/fmt_print.h"
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"

using std::max;
using std::min;
using std::vector;

struct Interval {
  int left, right;
};

vector<Interval> AddInterval(const vector<Interval>& disjoint_intervals,
                             Interval new_interval) {
  size_t i = 0;
  vector<Interval> result;

  // Processes intervals in disjoint_intervals which come before new_interval.
  while (i < size(disjoint_intervals) &&
         new_interval.left > disjoint_intervals[i].right) {
    result.emplace_back(disjoint_intervals[i++]);
  }

  // Processes intervals in disjoint_intervals which overlap with
  // new_interval.
  while (i < size(disjoint_intervals) &&
         new_interval.right >= disjoint_intervals[i].left) {
    // If [a, b] and [c, d] overlap, their union is [min(a, c),max(b, d)].
    new_interval = {min(new_interval.left, disjoint_intervals[i].left),
                    max(new_interval.right, disjoint_intervals[i].right)};
    ++i;
  }
  result.emplace_back(new_interval);

  // Processes intervals in disjoint_intervals which come after new_interval.
  result.insert(end(result), begin(disjoint_intervals) + i,
                end(disjoint_intervals));
  return result;
}

namespace test_framework {
template <>
struct SerializationTrait<Interval> : UserSerTrait<Interval, int, int> {
  static std::vector<std::string> GetMetricNames(const std::string& arg_name) {
    return {FmtStr("length({})", arg_name)};
  }

  static std::vector<int> GetMetrics(const Interval& x) {
    return {x.right - x.left};
  }
};
}  // namespace test_framework
bool operator==(const Interval& a, const Interval& b) {
  return a.left == b.left && a.right == b.right;
}

std::ostream& operator<<(std::ostream& out, const Interval& i) {
  return PrintTo(out, std::make_tuple(i.left, i.right));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"disjoint_intervals", "new_interval"};
  return GenericTestMain(args, "interval_add.cc", "interval_add.tsv",
                         &AddInterval, DefaultComparator{}, param_names);
}
