#include <vector>

using std::vector;

// Returns the number of valid entries after deletion.
int DeleteDuplicates(vector<int>* A_ptr) {
  // Implement this placeholder.
  return 0;
}

vector<int> DeleteDuplicatesWrapper(vector<int> A) {
  int end = DeleteDuplicates(&A);
  A.resize(end);
  return A;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  GenericTestMain(args, "sorted_array_remove_dups.tsv",
                  &DeleteDuplicatesWrapper, DefaultComparator{}, param_names);
  return 0;
}
