#include <vector>

using std::vector;

vector<int> Multiply(vector<int> num1, vector<int> num2) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num1", "num2"};
  return GenericTestMain(args, timeout_seconds, "int_as_array_multiply.tsv",
                         &Multiply, DefaultComparator{}, param_names);
}
