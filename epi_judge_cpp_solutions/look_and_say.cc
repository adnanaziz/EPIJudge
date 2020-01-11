#include <string>

#include "test_framework/generic_test.h"

using std::string;
using std::to_string;

string NextNumber(const string& s);

string LookAndSay(int n) {
  string s = "1";
  for (int i = 1; i < n; ++i) {
    s = NextNumber(s);
  }
  return s;
}

string NextNumber(const string& s) {
  string result;
  for (int i = 0; i < size(s); ++i) {
    int count = 1;
    while (i + 1 < size(s) && s[i] == s[i + 1]) {
      ++i, ++count;
    }
    result += to_string(count) + s[i];
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "look_and_say.cc", "look_and_say.tsv",
                         &LookAndSay, DefaultComparator{}, param_names);
}
