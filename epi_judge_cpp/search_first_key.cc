#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

int SearchFirstOfK(const vector<int>& A, int k) {
    int left = 0, right = A.size() - 1, result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (A[mid] < k) {
            left = mid + 1;
        }
        else if (A[mid] == k) {
            result = mid;
            right = mid - 1;
        }
        else {
            right = mid - 1;
        }
    }
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "k"};
  return GenericTestMain(args, "search_first_key.cc", "search_first_key.tsv",
                         &SearchFirstOfK, DefaultComparator{}, param_names);
}
