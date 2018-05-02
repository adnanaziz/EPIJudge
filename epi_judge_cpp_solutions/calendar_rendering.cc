#include <algorithm>
#include <iterator>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"

using std::max;
using std::vector;

struct Event {
  int start, finish;
};

struct Endpoint {
  int time;
  bool is_start;
};

int FindMaxSimultaneousEvents(const vector<Event>& A) {
  // Builds an array of all endpoints.
  vector<Endpoint> E;
  for (const Event& event : A) {
    E.emplace_back(Endpoint{event.start, true});
    E.emplace_back(Endpoint{event.finish, false});
  }
  // Sorts the endpoint array according to the time, breaking ties
  // by putting start times before end times.
  sort(begin(E), end(E), [](const Endpoint& a, const Endpoint& b) {
    // If times are equal, an endpoint that starts an interval comes first.
    return a.time != b.time ? a.time < b.time : (a.is_start && !b.is_start);
  });

  // Track the number of simultaneous events, and record the maximum
  // number of simultaneous events.
  int max_num_simultaneous_events = 0, num_simultaneous_events = 0;
  for (const Endpoint& endpoint : E) {
    if (endpoint.is_start) {
      ++num_simultaneous_events;
      max_num_simultaneous_events =
          max(num_simultaneous_events, max_num_simultaneous_events);
    } else {
      --num_simultaneous_events;
    }
  }
  return max_num_simultaneous_events;
}

template <>
struct SerializationTraits<Event> : UserSerTraits<Event, int, int> {};

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "calendar_rendering.cc",
                         "calendar_rendering.tsv", &FindMaxSimultaneousEvents,
                         DefaultComparator{}, param_names);
}
