#include <string>

#include "test_framework/generic_test.h"

using std::string;

string SnakeString(const string& s) {
  string result;
  // Outputs the first row, i.e., s[1], s[5], s[9], ...
  for (int i = 1; i < size(s); i += 4) {
    result += s[i];
  }
  // Outputs the second row, i.e., s[0], s[2], s[4], ...
  for (int i = 0; i < size(s); i += 2) {
    result += s[i];
  }
  // Outputs the third row, i.e., s[3], s[7], s[11], ...
  for (int i = 3; i < size(s); i += 4) {
    result += s[i];
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "snake_string.cc", "snake_string.tsv",
                         &SnakeString, DefaultComparator{}, param_names);
}
