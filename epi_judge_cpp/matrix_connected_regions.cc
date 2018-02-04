#include <deque>
#include <vector>

#include "test_framework/test_timer.h"

using std::deque;
using std::vector;

void FlipColor(int x, int y, vector<deque<bool>>* image_ptr) {
  // Implement this placeholder.
  return;
}

vector<vector<int>> FlipColorWrapper(TestTimer& timer, int x, int y,
                                     vector<vector<int>> image) {
  vector<deque<bool>> b;
  b.reserve(image.size());
  for (const vector<int>& row : image) {
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

  image.resize(b.size());

  for (int i = 0; i < image.size(); ++i) {
    image[i].resize(b.size());
    for (int j = 0; j < image[i].size(); ++j) {
      image[i][j] = b[i][j];
    }
  }
  return image;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"timer", "x", "y", "image"};
  GenericTestMain(args, "painting.tsv", &FlipColorWrapper, DefaultComparator{},
                  param_names);
  return 0;
}
