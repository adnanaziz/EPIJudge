#include <string>
#include <vector>

#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

using std::vector;

void Rearrange(vector<int>* A_ptr) {
  // Implement this placeholder.
  return;
}

void CheckAnswer(const vector<int>& A) {
  for (int i = 0; i < A.size(); ++i) {
    if (i % 2) {
      if (A[i] < A[i - 1]) {
        throw TestFailure(
            std::to_string(i) + "th element (" + std::to_string(A[i]) +
            ") shall be greater than or equal to " + std::to_string(i - 1) +
            "th element (" + std::to_string(A[i - 1]) + ")");
      }
      if (i + 1 < A.size()) {
        if (A[i] < A[i + 1]) {
          throw TestFailure(
              std::to_string(i) + "th element (" + std::to_string(A[i]) +
              ") shall be greater than or equal to " + std::to_string(i + 1) +
              "th element (" + std::to_string(A[i + 1]) + ")");
        }
      }
    } else {
      if (i > 0) {
        if (A[i - 1] < A[i]) {
          throw TestFailure(std::to_string(i - 1) + "th element (" +
                            std::to_string(A[i - 1]) +
                            ") shall be greater than or equal to " +
                            std::to_string(i) + "th element (" +
                            std::to_string(A[i]) + ")");
        }
      }
      if (i + 1 < A.size()) {
        if (A[i + 1] < A[i]) {
          throw TestFailure(std::to_string(i + 1) + "th element (" +
                            std::to_string(A[i + 1]) +
                            ") shall be greater than or equal to " +
                            std::to_string(i) + "th element (" +
                            std::to_string(A[i]) + ")");
        }
      }
    }
  }
}

void RearrangeWrapper(TimedExecutor& executor, vector<int> A) {
  executor.Run([&] { Rearrange(&A); });

  CheckAnswer(A);
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "A"};
  return GenericTestMain(args, timeout_seconds, "alternating_array.tsv",
                         &RearrangeWrapper, DefaultComparator{}, param_names);
}
