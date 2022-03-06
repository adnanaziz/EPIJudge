#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;

struct Interval {
  int left, right;
};

int FindMinimumVisits(vector<Interval> intervals) {
    
    if (intervals.empty())
        return 0;
    std::sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.right < b.right;
        });
    
    int min_visit = intervals.front().right;

    vector<int> visits;
    visits.emplace_back(min_visit);
    for (const Interval& intrvl : intervals) {
        if (min_visit < intrvl.left) {
            min_visit = intrvl.right;
            visits.emplace_back(min_visit);
        }
    }
    return visits.size();
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
