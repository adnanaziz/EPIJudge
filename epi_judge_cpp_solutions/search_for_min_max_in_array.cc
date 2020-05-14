#include <algorithm>
#include <tuple>
#include <utility>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"

using std::max;
using std::min;
using std::minmax;
using std::pair;
using std::tie;
using std::vector;

struct MinMax {
  int smallest, largest;
};

MinMax FindMinMax(const vector<int>& A) {
  if (size(A) <= 1) {
    return {A.front(), A.front()};
  }

  int global_min, global_max;
  tie(global_min, global_max) = minmax(A[0], A[1]);
  // Process two elements at a time.
  for (int i = 2; i + 1 < size(A); i += 2) {
    const auto& [local_min, local_max] = minmax(A[i], A[i + 1]);
    global_min = min(global_min, local_min);
    global_max = max(global_max, local_max);
  }
  // If there is odd number of elements in the array, we still
  // need to compare the last element with the existing answer.
  if (size(A) % 2) {
    global_min = min(global_min, A.back());
    global_max = max(global_max, A.back());
  }
  return {global_min, global_max};
}

namespace test_framework {
template <>
struct SerializationTrait<MinMax> : UserSerTrait<MinMax, int, int> {};
}  // namespace test_framework

bool operator==(const MinMax& lhs, const MinMax& rhs) {
  return std::tie(lhs.smallest, lhs.largest) ==
         std::tie(rhs.smallest, rhs.largest);
}

std::ostream& operator<<(std::ostream& out, const MinMax& x) {
  return out << "min: " << x.smallest << ", max: " << x.largest;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "search_for_min_max_in_array.cc",
                         "search_for_min_max_in_array.tsv", &FindMinMax,
                         DefaultComparator{}, param_names);
}
