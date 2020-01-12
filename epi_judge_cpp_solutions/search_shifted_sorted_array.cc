#include <vector>

#include "test_framework/generic_test.h"

using std::vector;

int SearchSmallest(const vector<int>& A) {
  int left = 0, right = size(A) - 1;
  while (left < right) {
    if (int mid = left + ((right - left) / 2); A[mid] > A[right]) {
      // Minimum must be in A[mid + 1, right].
      left = mid + 1;
    } else {  // A[mid] < A[right].
      // Minimum cannot be in A[mid + 1, right] so it must be in A[left, mid].
      right = mid;
    }
  }
  // Loop ends when left == right.
  return left;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "search_shifted_sorted_array.cc",
                         "search_shifted_sorted_array.tsv", &SearchSmallest,
                         DefaultComparator{}, param_names);
}
