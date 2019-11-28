#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;

struct Interval {
  int left, right;
};

int FindMinimumVisits(vector<Interval> intervals) {
  // TODO - you fill in here.
  return 0;
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
