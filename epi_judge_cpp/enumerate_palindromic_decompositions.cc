#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

#include "test_framework/generic_test.h"
using std::string;
using std::vector;

bool isPalindrome(const string& str) {

    for (int i = 0, j = str.size() - 1; i < j; i++, j--) {
        if (str[i] != str[j])
            return false;
    }
    return true;
}

void DirectedPalindromePartioning(int offset, const string& input_text, vector<string>* partial_result,
    vector<vector<string>>& results) {
    if (offset == input_text.size()) {
        results.push_back(*partial_result);
    }

    for (int i = offset + 1; i <= input_text.size(); i++) {
        string sbStr = input_text.substr(offset, i - offset);
        if (isPalindrome(sbStr)) {
            partial_result->push_back(sbStr);
            DirectedPalindromePartioning(i, input_text, partial_result, results);
            partial_result->pop_back();
        }
    }
}

vector<vector<string>> PalindromeDecompositions(const string& text) {
    vector<vector<string>> results;
    DirectedPalindromePartioning(0, text, new vector<string>, results);
    return results;
}
bool Comp(vector<vector<string>> expected, vector<vector<string>> result) {
  std::sort(begin(expected), end(expected));
  std::sort(begin(result), end(result));
  return expected == result;
};

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"text"};
  return GenericTestMain(args, "enumerate_palindromic_decompositions.cc",
                         "enumerate_palindromic_decompositions.tsv",
                         &PalindromeDecompositions, &Comp, param_names);
}
