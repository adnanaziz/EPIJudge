#include <algorithm>
#include <vector>

#include "test_framework/generic_test.h"

using std::swap;
using std::vector;

vector<int> NextPermutation(vector<int> perm) {
  // Find the first entry from the right that is smaller than the entry
  // immediately after it.
  auto inversion_point = is_sorted_until(rbegin(perm), rend(perm));
  if (inversion_point == rend(perm)) {
    // perm is sorted in decreasing order, so it's the last permutation.
    return {};
  }

  // Swap the entry referenced by inversion_point with smallest entry
  // appearing after inversion_point that is greater than the entry referenced
  // by inversion_point:
  //
  // 1.) Find the smallest entry after inversion_point that's greater than the
  //     entry referenced by inversion_point. Since perm must be sorted in
  //     decreasing order after inversion_point, we can use a fast algorithm
  //     to find this entry.
  auto least_upper_bound =
      upper_bound(rbegin(perm), inversion_point, *inversion_point);

  // 2.) Perform the swap.
  iter_swap(inversion_point, least_upper_bound);

  // Reverse the subarray that follows inversion_point.
  reverse(rbegin(perm), inversion_point);
  return perm;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"perm"};
  return GenericTestMain(args, "next_permutation.cc", "next_permutation.tsv",
                         &NextPermutation, DefaultComparator{}, param_names);
}
