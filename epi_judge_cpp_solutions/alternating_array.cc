#include <algorithm>
#include <string>
#include <vector>

#include "test_framework/fmt_print.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

using std::swap;
using std::vector;

void Rearrange(vector<int>* A_ptr) {
  vector<int>& A = *A_ptr;
  for (size_t i = 1; i < size(A); ++i) {
    if ((!(i % 2) && A[i - 1] < A[i]) || ((i % 2) && A[i - 1] > A[i])) {
      swap(A[i - 1], A[i]);
    }
  }
}

void CheckAnswer(const vector<int>& A) {
  for (int i = 0; i < A.size(); ++i) {
    if (i % 2) {
      if (A[i] < A[i - 1]) {
        throw TestFailure()
            .WithProperty(PropertyName::RESULT, A)
            .WithMismatchInfo(i, FmtStr("A[{}] <= A[{}]", i - 1, i),
                              FmtStr("{} > {}", A[i - 1], A[i]));
      }
      if (i + 1 < A.size()) {
        if (A[i] < A[i + 1]) {
          throw TestFailure()
              .WithProperty(PropertyName::RESULT, A)
              .WithMismatchInfo(i, FmtStr("A[{}] >= A[{}]", i, i + 1),
                                FmtStr("{} < {}", A[i], A[i + 1]));
        }
      }
    } else {
      if (i > 0) {
        if (A[i - 1] < A[i]) {
          throw TestFailure()
              .WithProperty(PropertyName::RESULT, A)
              .WithMismatchInfo(i, FmtStr("A[{}] >= A[{}]", i - 1, i),
                                FmtStr("{} < {}", A[i - 1], A[i]));
        }
      }
      if (i + 1 < A.size()) {
        if (A[i + 1] < A[i]) {
          throw TestFailure()
              .WithProperty(PropertyName::RESULT, A)
              .WithMismatchInfo(i, FmtStr("A[{}] <= A[{}]", i, i + 1),
                                FmtStr("{} > {}", A[i], A[i + 1]));
        }
      }
    }
  }
}

void RearrangeWrapper(TimedExecutor& executor, vector<int> A) {
  executor.Run([&] { Rearrange(&A); });

  CheckAnswer(A);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "A"};
  return GenericTestMain(args, "alternating_array.cc", "alternating_array.tsv",
                         &RearrangeWrapper, DefaultComparator{}, param_names);
}
