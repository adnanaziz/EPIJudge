#include <string>

#include "test_framework/test_failure_exception.h"

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
    throw TestFailureException("Decoding failed");
  }
  if (Encoding(decoded) != encoded) {
    throw TestFailureException("Encoding failed");
  }
}

#include "test_framework/generic_test.h"

int main(int argc, char *argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"encoded", "decoded"};
  GenericTestMain(args, "run_length_compression.tsv", &RleTester,
                  DefaultComparator{}, param_names);
  return 0;
}
