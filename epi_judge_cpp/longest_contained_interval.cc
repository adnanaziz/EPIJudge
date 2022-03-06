#include <vector>
#include <unordered_set>
#include "test_framework/generic_test.h"
using std::vector;

int LongestContainedRange(const vector<int>& A) {
    std::unordered_set<int> vect(A.begin(), A.end());
    int result = 0;


    while (!vect.empty()) {
        int a = *vect.begin();
        vect.erase(a);

        int lower_bound = a - 1;
        while (vect.count(lower_bound)) {
            vect.erase(lower_bound);
            lower_bound--;
        }

        int upper_bound = a + 1;
        while (vect.count(upper_bound)) {
            vect.erase(upper_bound);
            upper_bound++;
        }
    
        result = std::max(result, upper_bound - lower_bound - 1);

    }


    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(
      args, "longest_contained_interval.cc", "longest_contained_interval.tsv",
      &LongestContainedRange, DefaultComparator{}, param_names);
}
