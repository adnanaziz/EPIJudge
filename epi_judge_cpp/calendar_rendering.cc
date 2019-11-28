#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;

struct Event {
  int start, finish;
};
int FindMaxSimultaneousEvents(const vector<Event>& A) {
  // TODO - you fill in here.
  return 0;
}
namespace test_framework {
template <>
struct SerializationTrait<Event> : UserSerTrait<Event, int, int> {};
}  // namespace test_framework

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "calendar_rendering.cc",
                         "calendar_rendering.tsv", &FindMaxSimultaneousEvents,
                         DefaultComparator{}, param_names);
}
