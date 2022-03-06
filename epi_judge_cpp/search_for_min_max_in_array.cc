#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;
struct MinMax {
  int smallest, largest;
};

MinMax FindMinMax(const vector<int>& A) {
    if (A.size() <= 1)
        return { A.front(), A.front() };
    
    std::pair<int, int> global_min_max = std::minmax(A[0], A[1]);
    for (int i = 2; i < A.size() - 1; i++) {
        std::pair<int, int> local_min_max = std::minmax(A[i], A[i + 1]);

        global_min_max = {  std::min(global_min_max.first, local_min_max.first), 
                            std::max(global_min_max.second, local_min_max.second) };
    }
    if (A.size() % 2) {
       global_min_max = { std::min(global_min_max.first, A.back()),
                           std::max(global_min_max.second, A.back()) };
    }
    
    return { global_min_max.first, global_min_max.second};
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
