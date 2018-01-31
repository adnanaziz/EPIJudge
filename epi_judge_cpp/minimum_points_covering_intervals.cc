#include <vector>

#include "test_framework/test_utils_serialization_traits.h"

using std::vector;

struct Interval {
  int left, right;
};

int FindMinimumVisits(vector<Interval> intervals) {
  // Implement this placeholder.
  return 0;
}

template <>
struct SerializationTraits<Interval> : UserSerTraits<Interval, int, int> {};

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"intervals"};
  generic_test_main(argc, argv, param_names, "points_covering_intervals.tsv",
                    &FindMinimumVisits);
  return 0;
}
