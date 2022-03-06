#include <vector>

#include "test_framework/fmt_print.h"
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;

struct Interval {
  int left, right;
};

vector<Interval> AddInterval(const vector<Interval>& disjoint_intervals,
                             Interval new_interval) {
    vector<Interval> results;
    int indx = 0;
    while(indx < disjoint_intervals.size() && new_interval.left > disjoint_intervals[indx].right) {
        results.emplace_back(disjoint_intervals[indx++]);
    }

    while (indx < disjoint_intervals.size() && new_interval.right >= disjoint_intervals[indx].left) {
        new_interval = { std::min(new_interval.left, disjoint_intervals[indx].left),
                            std::max(new_interval.right, disjoint_intervals[indx].right) };
        indx++;
    }

    results.emplace_back(new_interval);

    results.insert(results.end(), disjoint_intervals.begin() + indx, disjoint_intervals.end());

    return results;
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
