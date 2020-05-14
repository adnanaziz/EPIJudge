#include <algorithm>
#include <cmath>
#include <limits>

#include "test_framework/generic_test.h"

using std::abs;
using std::max;
using std::numeric_limits;

enum class Ordering { kSmaller, kEqual, kLarger };

Ordering Compare(double a, double b);

double SquareRoot(double x) {
  // Decides the search range according to x's value relative to 1.0.
  double left, right;
  if (x < 1.0) {
    left = x, right = 1.0;
  } else {  // x >= 1.0.
    left = 1.0, right = x;
  }

  // Keeps searching as long as left != right, within tolerance.
  while (Compare(left, right) != Ordering::kEqual) {
    double mid = left + 0.5 * (right - left);
    if (double mid_squared = mid * mid;
        Compare(mid_squared, x) == Ordering::kLarger) {
      right = mid;
    } else {
      left = mid;
    }
  }
  return left;
}

Ordering Compare(double a, double b) {
  // Uses normalization for precision problem.
  double diff = (a - b) / max(abs(a), abs(b));
  return diff < -numeric_limits<double>::epsilon()
             ? Ordering::kSmaller
             : diff > numeric_limits<double>::epsilon() ? Ordering::kLarger
                                                        : Ordering::kEqual;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "real_square_root.cc", "real_square_root.tsv",
                         &SquareRoot, DefaultComparator{}, param_names);
}
