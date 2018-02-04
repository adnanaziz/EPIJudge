#include <vector>

#include "test_framework/test_timer.h"

using std::vector;

void RotateArray(int rotate_amount, vector<int>* A) {
  // Implement this placeholder.
  return;
}

vector<int> RotateArrayWrapper(TestTimer& timer, vector<int> A,
                               int rotate_amount) {
  vector<int> a_copy = A;
  timer.Start();
  RotateArray(rotate_amount, &a_copy);
  timer.Stop();
  return a_copy;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"timer", "A", "rotate_amount"};
  GenericTestMain(args, "rotate_array.tsv", &RotateArrayWrapper,
                  DefaultComparator{}, param_names);
  return 0;
}
