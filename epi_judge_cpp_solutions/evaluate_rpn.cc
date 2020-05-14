#include <functional>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>

#include "test_framework/generic_test.h"

using std::function;
using std::stack;
using std::string;
using std::stringstream;
using std::unordered_map;

int Evaluate(const string& expression) {
  stack<int> intermediate_results;
  stringstream ss(expression);
  string token;
  const char kDelimiter = ',';
  const unordered_map<string, function<int(int, int)>> kOperators = {
      {"+", [](int x, int y) { return x + y; }},
      {"-", [](int x, int y) { return x - y; }},
      {"*", [](int x, int y) { return x * y; }},
      {"/", [](int x, int y) { return x / y; }}};

  while (getline(ss, token, kDelimiter)) {
    if (kOperators.count(token)) {
      const int y = intermediate_results.top();
      intermediate_results.pop();
      const int x = intermediate_results.top();
      intermediate_results.pop();
      intermediate_results.emplace(kOperators.at(token)(x, y));
    } else {  // token is a number.
      intermediate_results.emplace(stoi(token));
    }
  }
  return intermediate_results.top();
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"expression"};
  return GenericTestMain(args, "evaluate_rpn.cc", "evaluate_rpn.tsv", &Evaluate,
                         DefaultComparator{}, param_names);
}
