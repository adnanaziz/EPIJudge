#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

int SearchSmallestHelper(const vector<int>& A, int left, int right) {
    if (left == right) return left;

    int mid = left + (right - left) / 2;
    if (A[mid] > A[right])
        return SearchSmallestHelper(A, mid+1, right);
    else if (A[mid] < A[right])
        return SearchSmallestHelper(A, left, mid);
    else {
        int left_val = SearchSmallestHelper(A, left, mid);
        int right_val = SearchSmallestHelper(A, mid + 1, right);

        return (left_val < right_val) ? left : right;
    }
}

int SearchSmallest(const vector<int>& A) {
  return SearchSmallestHelper(A, 0, A.size()-1);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "search_shifted_sorted_array.cc",
                         "search_shifted_sorted_array.tsv", &SearchSmallest,
                         DefaultComparator{}, param_names);
}
