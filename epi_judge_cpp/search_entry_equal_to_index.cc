#include <vector>

#include "test_framework/test_failure_exception.h"
#include "test_framework/test_timer.h"

using std::vector;

int SearchEntryEqualToItsIndex(const vector<int>& A) {
  // Implement this placeholder.
  return 0;
}

void SearchEntryEqualToItsIndexWrapper(TestTimer& timer, const vector<int>& A) {
  timer.Start();
  int result = SearchEntryEqualToItsIndex(A);
  timer.Stop();
  if (result != -1) {
    if (A[result] != result) {
      throw TestFailureException("Entry does not equal to its index");
    }
  } else {
    for (int i = 0; i < A.size(); ++i) {
      if (A[i] == i) {
        throw TestFailureException(
            "There are entries which equal to its index");
      }
    }
  }
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "binary_search_ai=i.tsv",
                    &SearchEntryEqualToItsIndexWrapper);
  return 0;
}
