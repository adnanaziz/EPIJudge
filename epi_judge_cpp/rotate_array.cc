#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"

using std::vector;

void RotateArray(int rotate_amount, vector<int>* A) {
  // Implement this placeholder.
  return;
}

vector<int> RotateArrayWrapper(TimedExecutor& executor, vector<int> A,
                               int rotate_amount) {
  executor.Run([&] { RotateArray(rotate_amount, &A); });
  return A;
}

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "A", "rotate_amount"};
  return GenericTestMain(args, timeout_seconds, "rotate_array.tsv",
                         &RotateArrayWrapper, DefaultComparator{}, param_names);
}
