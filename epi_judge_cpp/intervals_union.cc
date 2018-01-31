#include <vector>

#include "test_framework/test_timer.h"
#include "test_framework/test_utils_serialization_traits.h"

using std::vector;

struct Interval {
  struct Endpoint {
    bool is_closed;
    int val;
  };

  Endpoint left, right;
};

vector<Interval> UnionOfIntervals(vector<Interval> intervals) {
  // Implement this placeholder.
  return {};
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

template <>
struct SerializationTraits<FlatInterval>
    : UserSerTraits<FlatInterval, int, bool, int, bool> {};

std::ostream& operator<<(std::ostream& out, const FlatInterval& i) {
  return out << (i.left_is_closed ? '<' : '(') << i.left_val << ", "
             << i.right_val << (i.right_is_closed ? '>' : ')');
}

std::vector<FlatInterval> UnionOfIntervalsWrapper(
    TestTimer& timer, const std::vector<FlatInterval>& intervals) {
  std::vector<Interval> casted;
  for (const FlatInterval& i : intervals) {
    casted.push_back(static_cast<Interval>(i));
  }

  timer.Start();
  std::vector<Interval> result = UnionOfIntervals(casted);
  timer.Stop();

  return {begin(result), end(result)};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"timer", "intervals"};
  generic_test_main(argc, argv, param_names, "intervals_union.tsv",
                    &UnionOfIntervalsWrapper);
  return 0;
}
