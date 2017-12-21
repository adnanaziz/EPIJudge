#include <set>
#include <vector>

#include "test_framework/test_failure_exception.h"
#include "test_framework/test_timer.h"

using std::vector;

void EvenOdd(vector<int>* A_ptr) {
  // Implement this placeholder.
  return;
}

void EvenOddWrapper(TestTimer& timer, vector<int> A) {
  std::multiset<int> before(begin(A), end(A));

  timer.Start();
  EvenOdd(&A);
  timer.Stop();

  bool in_odd = false;
  for (int a : A) {
    if (a % 2 == 0) {
      if (in_odd) {
        throw TestFailureException("Even elements appear in odd part");
      }
    } else {
      in_odd = true;
    }
  }

  std::multiset<int> after(begin(A), end(A));
  if (before != after) {
    throw TestFailureException("Elements mismatch");
  }
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "even_odd_array.tsv", &EvenOddWrapper);
  return 0;
}
