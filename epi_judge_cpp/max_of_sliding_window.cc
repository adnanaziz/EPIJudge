#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/test_utils_serialization_traits.h"

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
  // Implement this placeholder.
  return {};
}

template <>
struct SerializationTraits<TrafficElement>
    : UserSerTraits<TrafficElement, int, double> {};

std::ostream& operator<<(std::ostream& out, const TrafficElement& te) {
  return out << '[' << te.time << ", " << te.volume << ']';
};

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "w"};
  return GenericTestMain(args, timeout_seconds, "max_of_sliding_window.tsv",
                         &CalculateTrafficVolumes, DefaultComparator{},
                         param_names);
}
