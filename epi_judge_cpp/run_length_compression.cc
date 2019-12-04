#include <string>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
using std::string;
string Decoding(const string &s) {
  // TODO - you fill in here.
  return "";
}
string Encoding(const string &s) {
  // TODO - you fill in here.
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

int main(int argc, char *argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"encoded", "decoded"};
  return GenericTestMain(args, "run_length_compression.cc",
                         "run_length_compression.tsv", &RleTester,
                         DefaultComparator{}, param_names);
}
