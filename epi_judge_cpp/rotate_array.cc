#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"
using std::vector;

long long Gcd(long long x, long long y) {

    if (x == 0) return y;
    if (y == 0) return x;

    if (x == y) {
        return x;
    }
    else if (!(x & 1) && !(y & 1)) {
        return Gcd(x >> 1, y >> 1) << 1;
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

void CyclicPermutation(int rotate_amount, int offset, int cycle_len, vector<int>* A) {
    vector<int>& ARef = *A;

    int temp = ARef[offset];
    for (int i = 1; i < cycle_len; i++) {
        std::swap(ARef[(offset + i*rotate_amount) % ARef.size()], temp);
    }

    ARef[offset] = temp;
}

void RotateArray(int rotate_amount, vector<int>* A) {
    rotate_amount %= A->size();
    vector<int>& ARef = *A;
 
    /*
    int num_cycles = Gcd(rotate_amount, ARef.size());

    int cycle_len = ARef.size() / num_cycles;

    for (int i = 0; i < num_cycles; i++) {
        CyclicPermutation(rotate_amount, i, cycle_len, A);
    }
    */

    std::reverse(A->begin(), A->end());
    std::reverse(A->begin(), A->begin() + rotate_amount);
    std::reverse(A->begin() + rotate_amount, A->end());
}

vector<int> RotateArrayWrapper(TimedExecutor& executor, vector<int> A,
                               int rotate_amount) {
  executor.Run([&] { RotateArray(rotate_amount, &A); });
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "A", "rotate_amount"};
  return GenericTestMain(args, "rotate_array.cc", "rotate_array.tsv",
                         &RotateArrayWrapper, DefaultComparator{}, param_names);
}
