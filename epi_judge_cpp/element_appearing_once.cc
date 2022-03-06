#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

int FindElementAppearsOnce(const vector<int>& A) {
    std::array<int, 32> count = {};

    for (int i = 0; i < A.size(); i++) {
        for(int j=0; j < 32; j++){
            if (A[i] & (1<<j)) {
                ++count[j];
            }
        }
    }

    int result = 0;
    for (int i = 0; i < 32; i++) {
        //if (count[i] & (1 << i)) {
            result |= (count[i] %3) * (1 << i);
        //}
    }

    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "element_appearing_once.cc",
                         "element_appearing_once.tsv", &FindElementAppearsOnce,
                         DefaultComparator{}, param_names);
}
