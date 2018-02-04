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

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"timer", "A"};
  GenericTestMain(args, "even_odd_array.tsv", &EvenOddWrapper,
                  DefaultComparator{}, param_names);
  return 0;
}
