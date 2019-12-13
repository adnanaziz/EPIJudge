#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "test_framework/generic_test.h"

using std::invalid_argument;
using std::string;
using std::stringstream;
using std::vector;

string ShortestEquivalentPath(const string& path) {
  if (empty(path)) {
    throw invalid_argument("Empty string is not a valid path.");
  }

  vector<string> path_names;  // Uses vector as a stack.
  // Special case: starts with "/", which is an absolute path.
  if (path.front() == '/') {
    path_names.emplace_back("/");
  }

  stringstream ss(path);
  string token;
  while (getline(ss, token, '/')) {
    if (token == "..") {
      if (empty(path_names) || path_names.back() == "..") {
        path_names.emplace_back(token);
      } else {
        if (path_names.back() == "/") {
          throw invalid_argument("Path error");
        }
        path_names.pop_back();
      }
    } else if (token != "." && token != "") {  // Must be a name.
      path_names.emplace_back(token);
    }
  }

  string result;
  if (!empty(path_names)) {
    result = path_names.front();
    for (int i = 1; i < size(path_names); ++i) {
      if (i == 1 && result == "/") {  // Avoid starting "//".
        result += path_names[i];
      } else {
        result += "/" + path_names[i];
      }
    }
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"path"};
  return GenericTestMain(args, "directory_path_normalization.cc",
                         "directory_path_normalization.tsv",
                         &ShortestEquivalentPath, DefaultComparator{},
                         param_names);
}
