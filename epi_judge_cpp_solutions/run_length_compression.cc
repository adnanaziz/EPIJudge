#include <cctype>
#include <string>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"

using std::string;
using std::to_string;

string Decoding(const string &s) {
  int count = 0;
  string result;
  for (const char &c : s) {
    if (isdigit(c)) {
      count = count * 10 + c - '0';
    } else {                    // c is a letter of alphabet.
      result.append(count, c);  // Appends count copies of c to result.
      count = 0;
    }
  }
  return result;
}

string Encoding(const string &s) {
  string result;
  for (int i = 1, count = 1; i <= size(s); ++i) {
    if (i == size(s) || s[i] != s[i - 1]) {
      // Found new character so write the count of previous character.
      result += to_string(count) + s[i - 1];
      count = 1;
    } else {  // s[i] == s[i - 1].
      ++count;
    }
  }
  return result;
}

void RleTester(const string &encoded, const string &decoded) {
  if (Decoding(encoded) != decoded) {
    throw TestFailure("Decoding failed");
  }
  if (Encoding(decoded) != encoded) {
    throw TestFailure("Encoding failed");
  }
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"encoded", "decoded"};
  return GenericTestMain(args, "run_length_compression.cc", "run_length_compression.tsv", &RleTester,
                         DefaultComparator{}, param_names);
}
// clang-format on
