#include <algorithm>
#include <vector>

#include "test_framework/generic_test.h"

using std::vector;

int SearchFirstOfK(const vector<int>& A, int k) {
  int left = 0, right = size(A) - 1, result = -1;
  // A[left, right] is the candidate set.
  while (left <= right) {
    if (int mid = left + ((right - left) / 2); A[mid] > k) {
      right = mid - 1;
    } else if (A[mid] == k) {
      result = mid;
      // Nothing to the right of mid can be the first occurrence of k.
      right = mid - 1;
    } else {  // A[mid] < k.
      left = mid + 1;
    }
  }
  return result;
}

int SearchFirstOfKAlternative(const vector<int>& A, int k) {
  auto result = std::lower_bound(begin(A), end(A), k);
  return *result == k ? distance(begin(A), result) : -1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "k"};
  return GenericTestMain(args, "search_first_key.cc", "search_first_key.tsv",
                         &SearchFirstOfK, DefaultComparator{}, param_names);
}
