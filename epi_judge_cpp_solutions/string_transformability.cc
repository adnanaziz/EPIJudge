#include <iterator>
#include <queue>
#include <string>
#include <unordered_set>

#include "test_framework/generic_test.h"

using std::queue;
using std::string;
using std::unordered_set;

// Uses BFS to find the least steps of transformation.

int TransformString(unordered_set<string> D, const string& s, const string& t) {
  struct StringWithDistance {
    string candidate_string;
    int distance;
  };
  queue<StringWithDistance> q;
  D.erase(s);  // Marks s as visited by erasing it in D.
  q.emplace(StringWithDistance{s, 0});

  while (!empty(q)) {
    StringWithDistance f(q.front());
    // Returns if we find a match.
    if (f.candidate_string == t) {
      return f.distance;  // Number of steps reaches t.
    }

    // Tries all possible transformations of f.candidate_string.
    string str = f.candidate_string;
    for (int i = 0; i < size(str); ++i) {
      for (char c = 'a'; c <= 'z'; ++c) {  // Iterates through 'a' ~ 'z'.
        str[i] = c;
        if (auto it = D.find(str); it != end(D)) {
          D.erase(it);
          q.emplace(StringWithDistance{str, f.distance + 1});
        }
      }
      str[i] = f.candidate_string[i];  // Reverts the change of str.
    }
    q.pop();
  }

  return -1;  // Cannot find a possible transformations.
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"D", "s", "t"};
  return GenericTestMain(args, "string_transformability.cc",
                         "string_transformability.tsv", &TransformString,
                         DefaultComparator{}, param_names);
}
