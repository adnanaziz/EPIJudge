#include <vector>

#include "test_framework/test_utils_serialization_traits.h"

using std::vector;

struct MinMax {
  int smallest, largest;
};

MinMax FindMinMax(const vector<int>& A) {
  // Implement this placeholder.
  return {0, 0};
}

template <>
struct SerializationTraits<MinMax> : UserSerTraits<MinMax, int, int> {};

bool operator==(const MinMax& lhs, const MinMax& rhs) {
  return std::tie(lhs.smallest, lhs.largest) ==
         std::tie(rhs.smallest, rhs.largest);
}

std::ostream& operator<<(std::ostream& out, const MinMax& x) {
  return out << "min: " << x.smallest << ", max: " << x.largest;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"A"};
  generic_test_main(argc, argv, param_names, "search_for_min_max_in_array.tsv",
                    &FindMinMax);
  return 0;
}
