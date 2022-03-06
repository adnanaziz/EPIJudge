#include <string>
#include <unordered_map>
#include "test_framework/generic_test.h"
using std::string;

bool CanFormPalindrome(const string& s) {
    std::unordered_map<char, int> charCount;
    for (char c : s) {
        ++charCount[c];
    }

    int odd_char_count = 0;
    for (const auto& p : charCount) {
        if ((p.second) % 2 && ++odd_char_count > 1)
            return false;
    }

  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "is_string_permutable_to_palindrome.cc",
                         "is_string_permutable_to_palindrome.tsv",
                         &CanFormPalindrome, DefaultComparator{}, param_names);
}
