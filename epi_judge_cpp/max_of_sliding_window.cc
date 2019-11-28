#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;

struct TrafficElement {
  bool operator==(const TrafficElement& that) const {
    return time == that.time && volume == that.volume;
  }
  int time;
  double volume;
};
vector<TrafficElement> CalculateTrafficVolumes(const vector<TrafficElement>& A,
                                               int w) {
  // TODO - you fill in here.
  return {};
}

namespace test_framework {
template <>
struct SerializationTrait<TrafficElement>
    : UserSerTrait<TrafficElement, int, double> {};
}  // namespace test_framework

std::ostream& operator<<(std::ostream& out, const TrafficElement& te) {
  return out << '[' << te.time << ", " << te.volume << ']';
};

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "w"};
  return GenericTestMain(args, "max_of_sliding_window.cc",
                         "max_of_sliding_window.tsv", &CalculateTrafficVolumes,
                         DefaultComparator{}, param_names);
}
