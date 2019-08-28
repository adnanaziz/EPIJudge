#include <algorithm>
#include <iterator>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
#include "test_framework/timed_executor.h"

using std::vector;

struct Interval {
  struct Endpoint {
    bool is_closed;
    int val;
  };

  Endpoint left, right;
};

vector<Interval> UnionOfIntervals(vector<Interval> intervals) {
  // Empty input.
  if (empty(intervals)) {
    return {};
  }

  // Sort intervals according to left endpoints of intervals.
  sort(begin(intervals), end(intervals),
       [](const Interval& a, const Interval& b) {
         if (a.left.val != b.left.val) {
           return a.left.val < b.left.val;
         }
         // Left endpoints are equal, so now see if one is closed and the
         // other open - closed intervals should appear first.
         return a.left.is_closed && !b.left.is_closed;
       });
  vector<Interval> result;
  for (Interval i : intervals) {
    if (!empty(result) &&
        (i.left.val < result.back().right.val ||
         (i.left.val == result.back().right.val &&
          (i.left.is_closed || result.back().right.is_closed)))) {
      if (i.right.val > result.back().right.val ||
          (i.right.val == result.back().right.val && i.right.is_closed)) {
        result.back().right = i.right;
      }
    } else {
      result.emplace_back(i);
    }
  }
  return result;
}

struct FlatInterval {
  int left_val;
  bool left_is_closed;
  int right_val;
  bool right_is_closed;

  FlatInterval(int left_val, bool left_is_closed, int right_val,
               bool right_is_closed)
      : left_val(left_val),
        left_is_closed(left_is_closed),
        right_val(right_val),
        right_is_closed(right_is_closed) {}

  explicit FlatInterval(Interval in)
      : left_val(in.left.val),
        left_is_closed(in.left.is_closed),
        right_val(in.right.val),
        right_is_closed(in.right.is_closed) {}

  operator Interval() const {
    return {{left_is_closed, left_val}, {right_is_closed, right_val}};
  }

  bool operator==(const FlatInterval& rhs) const {
    return std::tie(left_val, left_is_closed, right_val, right_is_closed) ==
           std::tie(rhs.left_val, rhs.left_is_closed, rhs.right_val,
                    rhs.right_is_closed);
  }
};

namespace test_framework {
template <>
struct SerializationTrait<FlatInterval>
    : UserSerTrait<FlatInterval, int, bool, int, bool> {};
}  // namespace test_framework

std::ostream& operator<<(std::ostream& out, const FlatInterval& i) {
  return out << (i.left_is_closed ? '<' : '(') << i.left_val << ", "
             << i.right_val << (i.right_is_closed ? '>' : ')');
}

std::vector<FlatInterval> UnionOfIntervalsWrapper(
    TimedExecutor& executor, const std::vector<FlatInterval>& intervals) {
  std::vector<Interval> casted;
  for (const FlatInterval& i : intervals) {
    casted.push_back(static_cast<Interval>(i));
  }

  std::vector<Interval> result =
      executor.Run([&] { return UnionOfIntervals(casted); });

  return {begin(result), end(result)};
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "intervals"};
  return GenericTestMain(args, "intervals_union.cc", "intervals_union.tsv",
                         &UnionOfIntervalsWrapper, DefaultComparator{},
                         param_names);
}
