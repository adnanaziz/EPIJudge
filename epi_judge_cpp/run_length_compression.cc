#include <string>

#include "test_framework/test_failure.h"

using std::string;

string Decoding(const string &s) {
  // Implement this placeholder.
  return "";
}

string Encoding(const string &s) {
  // Implement this placeholder.
  return "";
}

void RleTester(const string &encoded, const string &decoded) {
  if (Decoding(encoded) != decoded) {
    throw TestFailure("Decoding failed");
  }
  if (Encoding(decoded) != encoded) {
    throw TestFailure("Encoding failed");
  }
}

#include "test_framework/generic_test.h"

int main(int argc, char *argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"encoded", "decoded"};
  return GenericTestMain(args, timeout_seconds, "run_length_compression.tsv",
                         &RleTester, DefaultComparator{}, param_names);
}
