#include <algorithm>
#include <vector>

#include "test_framework/generic_test.h"

using std::max;
using std::vector;

int FindMaxSubarray(const vector<int>& A);
int FindCircularMaxSubarray(const vector<int>& A);

int MaxSubarraySumInCircular(const vector<int>& A) {
  return max(FindMaxSubarray(A), FindCircularMaxSubarray(A));
}

// Calculates the non-circular solution.
int FindMaxSubarray(const vector<int>& A) {
  int maximum_till = 0, maximum = 0;
  for (int a : A) {
    maximum_till = max(a, a + maximum_till);
    maximum = max(maximum, maximum_till);
  }
  return maximum;
}

vector<int> ComputeRunningMaximum(const vector<int>& A) {
  vector<int> running_maximum;
  int sum = A.front();
  running_maximum.emplace_back(sum);
  for (int i = 1; i < size(A); ++i) {
    sum += A[i];
    running_maximum.emplace_back(max(running_maximum.back(), sum));
  }
  return running_maximum;
}

// Calculates the solution which is circular.
int FindCircularMaxSubarray(const vector<int>& A) {
  // Maximum subarray sum starts at index 0 and ends at or before index i.
  vector<int> maximum_begin = ComputeRunningMaximum(A);

  // Maximum subarray sum starts at index i + 1 and ends at the last element.
  vector<int> maximum_end = ComputeRunningMaximum({crbegin(A), crend(A)});
  maximum_end.pop_back();
  reverse(begin(maximum_end), end(maximum_end));
  maximum_end.emplace_back(0);

  // Calculates the maximum subarray which is circular.
  int circular_max = 0;
  for (int i = 0; i < size(A); ++i) {
    circular_max = max(circular_max, maximum_begin[i] + maximum_end[i]);
  }
  return circular_max;
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"A"};
  return GenericTestMain(args, "maximum_subarray_in_circular_array.cc", "maximum_subarray_in_circular_array.tsv", &MaxSubarraySumInCircular,
                         DefaultComparator{}, param_names);
}
// clang-format on
