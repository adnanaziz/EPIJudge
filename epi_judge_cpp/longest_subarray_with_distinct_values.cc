#include <vector>
#include <unordered_map>
#include "test_framework/generic_test.h"
using std::vector;

int LongestSubarrayWithDistinctEntries(const vector<int>& A) {
    int longest_subarray = 0, result = 0;

    std::unordered_map<int, int> subarray;
    for (int i = 0; i < A.size(); i++) {
        auto& dup = subarray.emplace(A[i], i);
        if (!dup.second) {
            if(dup.first->second >= i - longest_subarray){
                result = std::max(result, longest_subarray );
                longest_subarray = i - dup.first->second - 1;
            }
            dup.first->second = i;
        }
        longest_subarray++;
    }

    result = std::max(result, longest_subarray);
    
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "longest_subarray_with_distinct_values.cc",
                         "longest_subarray_with_distinct_values.tsv",
                         &LongestSubarrayWithDistinctEntries,
                         DefaultComparator{}, param_names);
}
