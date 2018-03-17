#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/test_utils_serialization_traits.h"

using std::vector;

struct Jug {
  int low, high;
};

bool CheckFeasible(const vector<Jug>& jugs, int L, int H) {
  // Implement this placeholder.
  return true;
}

template <>
struct SerializationTraits<Jug> : UserSerTraits<Jug, int, int> {};

bool operator==(const Jug& lhs, const Jug& rhs) {
  return lhs.low == rhs.low && lhs.high == rhs.high;
}

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"jugs", "L", "H"};
  return GenericTestMain(args, timeout_seconds, "defective_jugs.tsv",
                         &CheckFeasible, DefaultComparator{}, param_names);
}
