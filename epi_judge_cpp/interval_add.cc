#include <vector>

#include "test_framework/test_utils_serialization_traits.h"

using std::vector;

struct Interval {
  int left, right;
};

vector<Interval> AddInterval(const vector<Interval>& disjoint_intervals,
                             Interval new_interval) {
  // Implement this placeholder.
  return {};
}

template <>
struct SerializationTraits<Interval> : UserSerTraits<Interval, int, int> {};

bool operator==(const Interval& a, const Interval& b) {
  return a.left == b.left && a.right == b.right;
}

std::ostream& operator<<(std::ostream& out, const Interval& i) {
  return EpiPrint(out, std::make_tuple(i.left, i.right));
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"disjoint_intervals", "new_interval"};
  generic_test_main(argc, argv, param_names, "interval_add.tsv", &AddInterval);
  return 0;
}
