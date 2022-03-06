#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

bool HasTwoSum(vector<int>& ASorted, int t) {
    int i = 0, j = ASorted.size() - 1;
    while (i <= j) {
        if (ASorted[i] + ASorted[j] == t)
            return true;
        else if (ASorted[i] + ASorted[j] < t)
            i++;
        else
            j--;
    }
    return false;
}

bool HasThreeSum(vector<int> A, int t) {
    std::sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++) {
        if (HasTwoSum(A, t - A[i]))
            return true;
    }
    
    return false;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "t"};
  return GenericTestMain(args, "three_sum.cc", "three_sum.tsv", &HasThreeSum,
                         DefaultComparator{}, param_names);
}
