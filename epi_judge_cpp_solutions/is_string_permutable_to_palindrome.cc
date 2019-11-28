#include <string>
#include <unordered_set>

#include "test_framework/generic_test.h"

using std::string;
using std::unordered_set;

bool CanFormPalindrome(const string& s) {
  unordered_set<char> chars_with_odd_frequency;
  for (char c : s) {
    if (chars_with_odd_frequency.count(c)) {
      // c now has appeared an even number of times.
      chars_with_odd_frequency.erase(c);
    } else {
      // c now has appeared an odd number of times.
      chars_with_odd_frequency.emplace(c);
    }
  }
  // A string can be permuted to form a palindrome if and only if the number
  // of chars whose frequencies is odd is at most 1.
  return size(chars_with_odd_frequency) <= 1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "is_string_permutable_to_palindrome.cc",
                         "is_string_permutable_to_palindrome.tsv",
                         &CanFormPalindrome, DefaultComparator{}, param_names);
}
