#include <algorithm>
#include <vector>

#include "test_framework/generic_test.h"

using std::swap;
using std::vector;

// A is passed by value argument, since we change it.
int FindFirstMissingPositive(vector<int> A) {
  // Record which values are present by writing A[i] to index A[i] - 1 if A[i]
  // is between 1 and size(A), inclusive. We save the value at index A[i] - 1
  // by swapping it with the entry at i. If A[i] is negative or greater than
  // n, we just advance i.
  for (int i = 0; i < size(A); ++i) {
    while (0 < A[i] && A[i] <= size(A) && A[i] != A[A[i] - 1]) {
      swap(A[i], A[A[i] - 1]);
    }
  }

  // Second pass through A to search for the first index i such that
  // A[i] != i+1, indicating that i + 1 is absent. If all numbers between 1
  // and size(A) are present, the smallest missing positive is size(A) + 1.
  for (int i = 0; i < size(A); ++i) {
    if (A[i] != i + 1) {
      return i + 1;
    }
  }
  return size(A) + 1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "first_missing_positive_entry.cc",
                         "first_missing_positive_entry.tsv",
                         &FindFirstMissingPositive, DefaultComparator{},
                         param_names);
}
