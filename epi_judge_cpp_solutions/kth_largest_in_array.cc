#include <algorithm>
#include <functional>
#include <random>
#include <stdexcept>
#include <vector>

#include "test_framework/generic_test.h"

using std::default_random_engine;
using std::function;
using std::greater;
using std::length_error;
using std::less;
using std::random_device;
using std::swap;
using std::uniform_int_distribution;
using std::vector;

int FindKth(int, function<bool(int, int)>, vector<int>*);
int PartitionAroundPivot(int, int, int, function<bool(int, int)>, vector<int>*);

// The numbering starts from one, i.e., if A = [3, 1, -1, 2] then
// FindKthLargest(1, A) returns 3, FindKthLargest(2, A) returns 2,
// FindKthLargest(3, A) returns 1, and FindKthLargest(4, A) returns -1.
int FindKthLargest(int k, vector<int>* A_ptr) {
  return FindKth(k, greater<int>(), A_ptr);
}

// The numbering starts from one, i.e., if A = [3, 1, -1, 2] then
// FindKthSmallest(1, A) returns -1, FindKthSmallest(2, A) returns 1,
// FindKthSmallest(3, A) returns 2, and FindKthSmallest(4, A) returns 3.
int FindKthSmallest(int k, vector<int>* A_ptr) {
  return FindKth(k, less<int>(), A_ptr);
}

int FindKth(int k, function<bool(int, int)> comp, vector<int>* A_ptr) {
  vector<int>& A = *A_ptr;
  int left = 0, right = size(A) - 1;
  default_random_engine gen((random_device())());
  while (left <= right) {
    // Generates a random integer in [left, right].
    int pivot_idx = uniform_int_distribution<int>{left, right}(gen);

    if (int new_pivot_idx =
            PartitionAroundPivot(left, right, pivot_idx, comp, &A);
        new_pivot_idx == k - 1) {
      return A[new_pivot_idx];
    } else if (new_pivot_idx > k - 1) {
      right = new_pivot_idx - 1;
    } else {  // new_pivot_idx < k - 1.
      left = new_pivot_idx + 1;
    }
  }

  throw length_error("no k-th node in array A");
}

// Partition A[left, right] around pivot_idx, returns the new index of the
// pivot, new_pivot_idx, after partition. After partitioning, A[left,
// new_pivot_idx - 1] contains elements that are "greater than" the pivot, and
// A[new_pivot_idx + 1, right] contains elements that are "less than" the
// pivot.
//
// Note: "greater than" and "less than" are defined by the Compare object.
//
// Returns the new index of the pivot element after partition.
int PartitionAroundPivot(int left, int right, int pivot_idx,
                         function<bool(int, int)> comp, vector<int>* A_ptr) {
  vector<int>& A = *A_ptr;
  int pivot_value = A[pivot_idx];
  int new_pivot_idx = left;
  swap(A[pivot_idx], A[right]);
  for (int i = left; i < right; ++i) {
    if (comp(A[i], pivot_value)) {
      swap(A[i], A[new_pivot_idx++]);
    }
  }
  swap(A[right], A[new_pivot_idx]);
  return new_pivot_idx;
}

int FindKthLargestWrapper(int k, vector<int>& A) {
  return FindKthLargest(k, &A);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"k", "A"};
  return GenericTestMain(args, "kth_largest_in_array.cc",
                         "kth_largest_in_array.tsv", &FindKthLargestWrapper,
                         DefaultComparator{}, param_names);
}
