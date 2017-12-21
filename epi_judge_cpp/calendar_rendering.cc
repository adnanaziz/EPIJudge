#include <vector>

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

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "calendar_rendering.tsv",
                    &FindMaxSimultaneousEvents);
  return 0;
}
