#include <algorithm>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"

using std::vector;

void RotateArray(int rotate_amount, vector<int>* A) {
  rotate_amount %= size(*A);
  reverse(begin(*A), end(*A));
  reverse(begin(*A), begin(*A) + rotate_amount);
  reverse(begin(*A) + rotate_amount, end(*A));
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
