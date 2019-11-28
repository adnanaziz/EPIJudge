#include <queue>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"

#define main _main
#include "queue_with_max_using_deque.cc"
#undef main

using std::queue;
using std::vector;

struct TrafficElement {
  // Following operators are needed for QueueWithMax with maximum.
  bool operator<(const TrafficElement& that) const {
    return volume < that.volume || (volume == that.volume && time < that.time);
  }

  bool operator==(const TrafficElement& that) const {
    return time == that.time && volume == that.volume;
  }

  bool operator<=(const TrafficElement& that) const { return !(that < *this); }

  int time;
  double volume;
};

vector<TrafficElement> CalculateTrafficVolumes(const vector<TrafficElement>& A,
                                               int w) {
  QueueWithMax<TrafficElement> sliding_window;
  vector<TrafficElement> maximum_volumes;
  for (const TrafficElement& traffic_info : A) {
    sliding_window.Enqueue(traffic_info);
    while (traffic_info.time - sliding_window.Head().time > w) {
      sliding_window.Dequeue();
    }
    maximum_volumes.push_back({traffic_info.time, sliding_window.Max().volume});
  }
  return maximum_volumes;
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
