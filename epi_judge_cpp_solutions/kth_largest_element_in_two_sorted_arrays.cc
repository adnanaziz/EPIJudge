#include <algorithm>
#include <limits>
#include <vector>

#include "test_framework/generic_test.h"

using std::max;
using std::min;
using std::numeric_limits;
using std::vector;

int FindKthInTwoSortedArrays(const vector<int>& A, const vector<int>& B,
                             int k) {
  // Lower bound of elements we will choose in A.
  int b = max(0, static_cast<int>(k - size(B)));
  // Upper bound of elements we will choose in A.
  int t = min(static_cast<int>(size(A)), k);

  while (b < t) {
    int x = b + ((t - b) / 2);
    int A_x_1 = x <= 0 ? numeric_limits<int>::min() : A[x - 1];
    int A_x = x >= size(A) ? numeric_limits<int>::max() : A[x];
    int B_k_x_1 = k - x <= 0 ? numeric_limits<int>::min() : B[k - x - 1];
    int B_k_x = k - x >= size(B) ? numeric_limits<int>::max() : B[k - x];

    if (A_x < B_k_x_1) {
      b = x + 1;
    } else if (A_x_1 > B_k_x) {
      t = x - 1;
    } else {
      // B[k - x - 1] <= A[x] && A[x - 1] < B[k - x].
      return max(A_x_1, B_k_x_1);
    }
  }

  int A_b_1 = b <= 0 ? numeric_limits<int>::min() : A[b - 1];
  int B_k_b_1 = k - b - 1 < 0 ? numeric_limits<int>::min() : B[k - b - 1];
  return max(A_b_1, B_k_b_1);
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"A", "B", "k"};
  return GenericTestMain(args, "kth_largest_element_in_two_sorted_arrays.cc", "kth_largest_element_in_two_sorted_arrays.tsv", &FindKthInTwoSortedArrays,
                         DefaultComparator{}, param_names);
}
// clang-format on
