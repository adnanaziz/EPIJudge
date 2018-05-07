#include <vector>
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;

struct Jug {
  int low, high;
};
bool CheckFeasible(const vector<Jug>& jugs, int L, int H) {
  // TODO - you fill in here.
  return true;
}
template <>
struct SerializationTraits<Jug> : UserSerTraits<Jug, int, int> {};

bool operator==(const Jug& lhs, const Jug& rhs) {
  return lhs.low == rhs.low && lhs.high == rhs.high;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"jugs", "L", "H"};
  return GenericTestMain(args, "defective_jugs.cc", "defective_jugs.tsv",
                         &CheckFeasible, DefaultComparator{}, param_names);
}
