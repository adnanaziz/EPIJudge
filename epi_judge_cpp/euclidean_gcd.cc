#include "test_framework/generic_test.h"
long long Gcd(long long x, long long y) {
    
    if (x == 0) return y;
    if (y == 0) return x;

    if (x == y) {
        return x;
    }
    else if (!(x & 1) && !(y & 1)) {
        return Gcd(x >> 1, y>>1) << 1;
    }
    else if (!(x & 1) && (y & 1)) {
        return Gcd(x >> 1, y);
    }
    else if ((x & 1) && !(y & 1)) {
        return Gcd(x, y >> 1);
    }
    else if (x > y) {
        return Gcd(x - y, y);
    }
    return Gcd(x, y - x);

}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "euclidean_gcd.cc", "gcd.tsv", &Gcd,
                         DefaultComparator{}, param_names);
}
