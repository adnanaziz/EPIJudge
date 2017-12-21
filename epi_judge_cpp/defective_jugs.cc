#include <vector>

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

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "defective_jugs.tsv", &CheckFeasible);
  return 0;
}
