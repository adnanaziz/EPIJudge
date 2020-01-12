#include <memory>
#include <vector>

#include "test_framework/generic_test.h"

using std::make_unique;
using std::vector;

int GetHeightHelper(int, int, vector<vector<int>>*);

int GetHeight(int cases, int drops) {
  return GetHeightHelper(
      cases, drops,
      make_unique<vector<vector<int>>>(cases + 1, vector<int>(drops + 1, -1))
          .get());
}

int GetHeightHelper(int cases, int drops, vector<vector<int>>* F) {
  if (cases == 0 || drops == 0) {
    return 0;
  } else if (cases == 1) {
    return drops;
  }
  if ((*F)[cases][drops] == -1) {
    (*F)[cases][drops] = GetHeightHelper(cases, drops - 1, F) +
                         GetHeightHelper(cases - 1, drops - 1, F) + 1;
  }
  return (*F)[cases][drops];
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"cases", "drops"};
  return GenericTestMain(args, "max_safe_height.cc", "max_safe_height.tsv",
                         &GetHeight, DefaultComparator{}, param_names);
}
