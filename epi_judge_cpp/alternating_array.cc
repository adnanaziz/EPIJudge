#include <vector>

#include "test_framework/test_failure_exception.h"
#include "test_framework/test_timer.h"

using std::vector;

void Rearrange(vector<int>* A_ptr) {
  // Implement this placeholder.
  return;
}

void CheckAnswer(const vector<int>& A) {
  for (int i = 0; i < A.size(); ++i) {
    if (i % 2) {
      if (A[i] < A[i - 1]) {
        throw TestFailureException("");
      }
      if (i + 1 < A.size()) {
        if (A[i] < A[i + 1]) {
          throw TestFailureException("");
        }
      }
    } else {
      if (i > 0) {
        if (A[i - 1] < A[i]) {
          throw TestFailureException("");
        }
      }
      if (i + 1 < A.size()) {
        if (A[i + 1] < A[i]) {
          throw TestFailureException("");
        }
      }
    }
  }
}

void RearrangeWrapper(TestTimer& timer, vector<int> A) {
  timer.Start();
  Rearrange(&A);
  timer.Stop();

  CheckAnswer(A);
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"timer", "A"};
  generic_test_main(argc, argv, param_names, "alternating_array.tsv",
                    &RearrangeWrapper);
  return 0;
}
