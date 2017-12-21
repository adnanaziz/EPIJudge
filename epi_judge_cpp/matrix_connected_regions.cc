#include <deque>
#include <vector>

#include "test_framework/test_timer.h"

using std::deque;
using std::vector;

void FlipColor(int x, int y, vector<deque<bool>>* A_ptr) {
  // Implement this placeholder.
  return;
}

vector<vector<int>> FlipColorWrapper(TestTimer& timer, int x, int y,
                                     vector<vector<int>> a) {
  vector<deque<bool>> b;
  b.reserve(a.size());
  for (const vector<int>& row : a) {
    deque<bool> tmp;
    tmp.resize(row.size());
    for (int i = 0; i < row.size(); ++i) {
      tmp[i] = static_cast<bool>(row[i]);
    }
    b.push_back(tmp);
  }

  timer.Start();
  FlipColor(x, y, &b);
  timer.Stop();

  a.resize(b.size());

  for (int i = 0; i < a.size(); ++i) {
    a[i].resize(b.size());
    for (int j = 0; j < a[i].size(); ++j) {
      a[i][j] = b[i][j];
    }
  }
  return a;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "painting.tsv", &FlipColorWrapper);
  return 0;
}
