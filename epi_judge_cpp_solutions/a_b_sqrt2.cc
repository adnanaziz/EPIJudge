#include <cmath>
#include <functional>
#include <set>
#include <vector>

#include "test_framework/generic_test.h"

using std::function;
using std::set;
using std::vector;

// These numbers have very interesting property, and people called it ugly
// numbers. It is also called Quadratic integer rings.

struct Number {
  Number(int a, int b) : a(a), b(b), val(a + b * sqrt(2)) {}

  int a, b;
  double val;
};

vector<double> GenerateFirstKABSqrt2(int k) {
  // Initial for 0 + 0 * sqrt(2).
  set<Number, function<bool(Number, Number)>> candidates(
      {{0, 0}}, [](const Number &a, const Number &b) { return a.val < b.val; });

  vector<double> result;
  while (size(result) < k) {
    auto next_smallest = cbegin(candidates);
    result.emplace_back(next_smallest->val);

    // Adds the next two numbers derived from next_smallest.
    candidates.emplace(next_smallest->a + 1, next_smallest->b);
    candidates.emplace(next_smallest->a, next_smallest->b + 1);
    candidates.erase(next_smallest);
  }
  return result;
}

int main(int argc, char *argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"k"};
  return GenericTestMain(args, "a_b_sqrt2.cc", "a_b_sqrt2.tsv",
                         &GenerateFirstKABSqrt2, DefaultComparator{},
                         param_names);
}
