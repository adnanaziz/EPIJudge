#include <algorithm>
#include <vector>

#include "test_framework/generic_test.h"

using std::exception;
using std::max;
using std::vector;

int BinarySearchUnknownLength(const vector<int>& A, int k) {
  // Find the possible range where k exists.
  int p = 0;
  while (true) {
    try {
      if (int idx = (1 << p) - 1; A.at(idx) == k) {
        return idx;
      } else if (A.at(idx) > k) {
        break;
      }
    } catch (const exception&) {
      break;
    }
    ++p;
  }

  // Binary search between indices 2^(p - 1) and 2^p - 2, inclusive.
  int left = max(0, 1 << (p - 1)), right = (1 << p) - 2;
  while (left <= right) {
    int mid = left + ((right - left) / 2);
    try {
      if (A.at(mid) == k) {
        return mid;
      } else if (A.at(mid) > k) {
        right = mid - 1;
      } else {  // A.at(mid) < k
        left = mid + 1;
      }
    } catch (const exception&) {
      right = mid - 1;  // Search the left part if out-of-bound.
    }
  }
  return -1;  // Nothing matched k.
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"A", "k"};
  return GenericTestMain(args, "search_unknown_length_array.cc", "search_unknown_length_array.tsv", &BinarySearchUnknownLength,
                         DefaultComparator{}, param_names);
}
// clang-format on
