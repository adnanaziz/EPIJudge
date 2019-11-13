#include <deque>
#include <initializer_list>
#include <queue>
#include <utility>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"

using std::deque;
using std::initializer_list;
using std::pair;
using std::queue;
using std::vector;

void FlipColor(int x, int y, vector<deque<bool>>* image_ptr) {
  vector<deque<bool>>& image = *image_ptr;
  const bool color = image[x][y];

  queue<pair<int, int>> q;
  image[x][y] = !color;  // Flips.
  q.emplace(x, y);
  while (!empty(q)) {
    const auto [x, y] = q.front();
    q.pop();
    for (const auto& [next_x, next_y] : vector<pair<int, int>>{
             {x, y + 1}, {x, y - 1}, {x + 1, y}, {x - 1, y}}) {
      if (next_x >= 0 && next_x < size(image) && next_y >= 0 &&
          next_y < size(image[next_x]) && image[next_x][next_y] == color) {
        // Flips the color.
        image[next_x][next_y] = !color;
        q.emplace(next_x, next_y);
      }
    }
  }
}

vector<vector<int>> FlipColorWrapper(TimedExecutor& executor, int x, int y,
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

  executor.Run([&] { FlipColor(x, y, &b); });

  image.resize(b.size());

  for (int i = 0; i < image.size(); ++i) {
    image[i].resize(b.size());
    for (int j = 0; j < image[i].size(); ++j) {
      image[i][j] = b[i][j];
    }
  }
  return image;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "x", "y", "image"};
  return GenericTestMain(args, "matrix_connected_regions.cc", "painting.tsv",
                         &FlipColorWrapper, DefaultComparator{}, param_names);
}
