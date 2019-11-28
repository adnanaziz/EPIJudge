#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;

struct DuplicateAndMissing {
  int duplicate, missing;
};

DuplicateAndMissing FindDuplicateMissing(const vector<int>& A) {
  // TODO - you fill in here.
  return {0, 0};
}

namespace test_framework {
template <>
struct SerializationTrait<DuplicateAndMissing>
    : UserSerTrait<DuplicateAndMissing, int, int> {};
}  // namespace test_framework

bool operator==(const DuplicateAndMissing& lhs,
                const DuplicateAndMissing& rhs) {
  return std::tie(lhs.duplicate, lhs.missing) ==
         std::tie(rhs.duplicate, rhs.missing);
}

std::ostream& operator<<(std::ostream& out, const DuplicateAndMissing& x) {
  return out << "duplicate: " << x.duplicate << ", missing: " << x.missing;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(
      args, "search_for_missing_element.cc", "find_missing_and_duplicate.tsv",
      &FindDuplicateMissing, DefaultComparator{}, param_names);
}
