#include <string>
#include <unordered_map>

#include "test_framework/generic_test.h"

using std::string;
using std::unordered_map;

int RomanToInteger(const string& s) {
  unordered_map<char, int> T = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                {'C', 100}, {'D', 500}, {'M', 1000}};

  int sum = T[s.back()];
  for (int i = s.length() - 2; i >= 0; --i) {
    if (T[s[i]] < T[s[i + 1]]) {
      sum -= T[s[i]];
    } else {
      sum += T[s[i]];
    }
  }
  return sum;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "roman_to_integer.cc", "roman_to_integer.tsv",
                         &RomanToInteger, DefaultComparator{}, param_names);
}
