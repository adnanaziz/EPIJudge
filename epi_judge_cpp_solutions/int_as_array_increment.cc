#include <vector>

#include "test_framework/generic_test.h"

using std::vector;

vector<int> PlusOne(vector<int> A) {
  ++A.back();
  for (int i = size(A) - 1; i > 0 && A[i] == 10; --i) {
    A[i] = 0, ++A[i - 1];
  }
  if (A[0] == 10) {
    // There is a carry-out, so we need one more digit to store the result.
    // A slick way to do this is to append a 0 at the end of the array,
    // and update the first entry to 1.
    A[0] = 1;
    A.emplace_back(0);
  }
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "int_as_array_increment.cc",
                         "int_as_array_increment.tsv", &PlusOne,
                         DefaultComparator{}, param_names);
}
