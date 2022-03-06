#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

// A is passed by value argument, since we change it.
int FindFirstMissingPositive(vector<int> A) {
    size_t i = 0;
    while (i < A.size()) {
        if (A[i] > 0 && A[i] <= A.size() && A[A[i]-1] != A[i]) {
            std::swap(A[i], A[A[i]-1]);
        }
        else {
            i++;
        }
    }

    for (i = 0; i < A.size();i++) {
        if (A[i] != i + 1) 
            return i + 1;
    }

    return A.size()+1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "first_missing_positive_entry.cc",
                         "first_missing_positive_entry.tsv",
                         &FindFirstMissingPositive, DefaultComparator{},
                         param_names);
}
