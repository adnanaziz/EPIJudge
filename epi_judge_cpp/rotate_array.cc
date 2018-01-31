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

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"timer", "A", "rotate_amount"};
  generic_test_main(argc, argv, param_names, "rotate_array.tsv",
                    &RotateArrayWrapper);
  return 0;
}
