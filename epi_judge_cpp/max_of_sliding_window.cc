#include <vector>

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

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"A", "w"};
  generic_test_main(argc, argv, param_names, "max_of_sliding_window.tsv",
                    &CalculateTrafficVolumes);
  return 0;
}
