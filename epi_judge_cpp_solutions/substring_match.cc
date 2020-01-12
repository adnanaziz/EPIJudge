#include <string>

#include "test_framework/generic_test.h"

using std::string;

// Returns the index of the first character of the substring if found, -1
// otherwise.
int RabinKarp(const string &t, const string &s) {
  if (size(s) > size(t)) {
    return -1;  // s is not a substring of t.
  }

  const int kBase = 26;
  int t_hash = 0, s_hash = 0;  // Hash codes for the substring of t and s.
  int power_s = 1;             // kBase^|s-1|.
  for (int i = 0; i < size(s); ++i) {
    power_s = i ? power_s * kBase : 1;
    t_hash = t_hash * kBase + t[i];
    s_hash = s_hash * kBase + s[i];
  }

  for (int i = size(s); i < size(t); ++i) {
    // Checks the two substrings are actually equal or not, to protect
    // against hash collision.
    if (t_hash == s_hash && !t.compare(i - size(s), size(s), s)) {
      return i - size(s);  // Found a match.
    }

    // Uses rolling hash to compute the new hash code.
    t_hash -= t[i - size(s)] * power_s;
    t_hash = t_hash * kBase + t[i];
  }

  // Tries to match s and t[size(t) - size(s), size(t) - 1].
  if (t_hash == s_hash && t.compare(size(t) - size(s), size(s), s) == 0) {
    return size(t) - size(s);
  }
  return -1;  // s is not a substring of t.
}

int main(int argc, char *argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"t", "s"};
  return GenericTestMain(args, "substring_match.cc", "substring_match.tsv",
                         &RabinKarp, DefaultComparator{}, param_names);
}
