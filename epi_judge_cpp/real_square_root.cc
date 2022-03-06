#include "test_framework/generic_test.h"
typedef enum{ SMALLER, EQUAL, BIGGER } Ordering;

Ordering CompareValue(double a, double b) {
    double diff = (a - b) / b;
    return (diff < -std::numeric_limits<double>::epsilon()) ? SMALLER : (diff > std::numeric_limits<double>::epsilon() ? BIGGER : EQUAL);
}

double SquareRoot(double x) {
    double left, right;
    if (x < 1) {
        left = x;
        right = 1.0;
    }
    else {
        left = 1.0;
        right = x;
    }

    while(CompareValue(left, right) == SMALLER) {
        double mid = left + (right - left) / 2;
        double mid_square = mid * mid;

        if (CompareValue(mid_square, x) == SMALLER)
            left = mid;
        else if (CompareValue(mid_square, x) == EQUAL)
            return mid;
        else
            right = mid;

    }

    return left;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "real_square_root.cc", "real_square_root.tsv",
                         &SquareRoot, DefaultComparator{}, param_names);
}
