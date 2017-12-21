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

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char *argv[]) {
  generic_test_main(argc, argv, "run_length_compression.tsv", &RleTester);
  return 0;
}
