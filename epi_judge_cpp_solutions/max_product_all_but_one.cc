#include <algorithm>
#include <functional>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

#include "test_framework/generic_test.h"

using std::max;
using std::multiplies;
using std::numeric_limits;
using std::vector;

int FindBiggestNMinusOneProduct(const vector<int>& A) {
  // Builds suffix products.
  vector<int> suffix_products(size(A));
  partial_sum(crbegin(A), crend(A), rbegin(suffix_products), multiplies<int>());

  // Finds the biggest product of (n - 1) numbers.
  int prefix_product = 1, max_product = numeric_limits<int>::min();
  for (int i = 0; i < size(A); ++i) {
    int suffix_product = i + 1 < size(A) ? suffix_products[i + 1] : 1;
    max_product = max(max_product, prefix_product * suffix_product);
    prefix_product *= A[i];
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
