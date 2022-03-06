#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

struct Subarray {
  int start = 0, end = 0;
};

Subarray FindLongestIncreasingSubarray(const vector<int>& A) {
    Subarray ans;
    int max_len = 1;
    int i = 0;
    
    while (i < A.size() - max_len) {
        bool isBig = false;

        int j = i+max_len;
        while(j > i) {
            if (A[j - 1] >= A[j]) {
                isBig = true;
                i = j;
                break;
            }
            j--;
        }

        if (!isBig) {
            i += max_len;
            while (i < A.size() && A[i - 1] < A[i]) {
                i++;
                max_len++;
            }
            ans = Subarray{ i - max_len, i - 1 };
        }
    }
    return ans;
}
int FindLongestIncreasingSubarrayWrapper(const vector<int>& A) {
  Subarray result = FindLongestIncreasingSubarray(A);
  return result.end - result.start + 1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(
      args, "longest_increasing_subarray.cc", "longest_increasing_subarray.tsv",
      &FindLongestIncreasingSubarrayWrapper, DefaultComparator{}, param_names);
}
