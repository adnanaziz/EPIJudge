#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

int FindBiggestNMinusOneProduct(const vector<int>& A) {
    /*
    vector<int> L, R(A.size());
    std::partial_sum(A.cbegin(), A.cend(), back_inserter(L), std::multiplies<int>());
    std::partial_sum(A.crbegin(), A.crend(), R.rbegin(), std::multiplies<int>());
    int max_product = std::numeric_limits<int>::min();

    for (int i = 0; i < A.size(); i++) {
        int forward = (i > 0) ? L[i-1] : 1;
        int backward = (i + 1) < A.size() ? R[i+1] : 1;

        max_product = std::max(max_product, forward * backward);
    }

    return max_product;
    */

    int least_negative_idx = -1, greatest_negative_idx = -1;
    int num_of_negative = 0;
    int least_non_negative_idx = -1;

    for (int i = 0; i < A.size(); i++) {

        if (A[i] < 0) {

            num_of_negative++;
            if (least_negative_idx == -1 || A[least_negative_idx] < A[i]) {
                least_negative_idx = i;
            }

            if (greatest_negative_idx == -1 || A[i] < A[greatest_negative_idx]) {
                greatest_negative_idx = i;
            }
        }
        else {
            if (least_non_negative_idx == -1 || A[i] < A[least_non_negative_idx])
                least_non_negative_idx = i;
        }
    }

    int indx_to_skip = num_of_negative % 2 ? least_negative_idx : 
                        (least_non_negative_idx != -1) ? least_non_negative_idx : greatest_negative_idx;

    int max_product = 1;
    for (int i = 0; i < A.size(); i++) {
        if(i != indx_to_skip){
            max_product *= A[i];
        }
    }

    return max_product;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(
      args, "max_product_all_but_one.cc", "max_product_all_but_one.tsv",
      &FindBiggestNMinusOneProduct, DefaultComparator{}, param_names);
}
