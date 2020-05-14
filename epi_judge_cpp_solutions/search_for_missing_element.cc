#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"

using std::vector;

struct DuplicateAndMissing {
  int duplicate, missing;
};

DuplicateAndMissing FindDuplicateMissing(const vector<int>& A) {
  // Compute the XOR of all numbers from 0 to |A| - 1 and all entries in A.
  int miss_XOR_dup = 0;
  for (int i = 0; i < size(A); ++i) {
    miss_XOR_dup ^= i ^ A[i];
  }

  // We need to find a bit that's set to 1 in miss_XOR_dup. Such a bit
  // must exist if there is a single missing number and a single duplicated
  // number in A.
  //
  // The bit-fiddling assignment below sets all of bits in differ_bit to 0
  // except for the least significant bit in miss_XOR_dup that's 1.
  int differ_bit = miss_XOR_dup & (~(miss_XOR_dup - 1));
  int miss_or_dup = 0;
  for (int i = 0; i < size(A); ++i) {
    // Focus on entries and numbers in which the differ_bit-th bit is 1.
    if (i & differ_bit) {
      miss_or_dup ^= i;
    }
    if (A[i] & differ_bit) {
      miss_or_dup ^= A[i];
    }
  }

  // miss_or_dup is either the missing value or the duplicated entry.
  if (find(begin(A), end(A), miss_or_dup) != end(A)) {
    return {miss_or_dup, miss_or_dup ^ miss_XOR_dup};
  }
  // miss_or_dup is the missing value.
  return {miss_or_dup ^ miss_XOR_dup, miss_or_dup};
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
