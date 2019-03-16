#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
vector<int> PlusOne(vector<int> A) {
    int i = A.size()-1;
    int carry = 1;
    while (carry != 0 && i >= 0)
    {
        int new_val = A[i]+carry;
        A[i] = new_val%10;
        carry = new_val/10;
        i--;
    }
    if (carry != 0) A.insert(A.begin(), 1);
    return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "int_as_array_increment.cc",
                         "int_as_array_increment.tsv", &PlusOne,
                         DefaultComparator{}, param_names);
}
