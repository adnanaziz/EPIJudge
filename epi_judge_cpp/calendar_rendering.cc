#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/test_utils_serialization_traits.h"

using std::vector;

struct Event {
  int start, finish;
};

int FindMaxSimultaneousEvents(const vector<Event>& A) {
  // Implement this placeholder.
  return 0;
}

template <>
struct SerializationTraits<Event> : UserSerTraits<Event, int, int> {};

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, timeout_seconds, "calendar_rendering.tsv",
                         &FindMaxSimultaneousEvents, DefaultComparator{},
                         param_names);
}
