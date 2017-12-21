#include <vector>

using std::vector;

void RotateArray(int i, vector<int>* A) {
  // Implement this placeholder.
  return;
}

vector<int> RotateArrayWrapper(vector<int> a, int k) {
  RotateArray(k, &a);
  return a;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "rotate_array.tsv", &RotateArrayWrapper);
  return 0;
}
