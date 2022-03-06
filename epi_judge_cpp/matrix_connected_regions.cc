#include <deque>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"
using std::deque;
using std::vector;

void FlipColorBFS(int x, int y, vector<deque<bool>>* image_ptr) {
    vector<deque<bool>>& image = *image_ptr;
    
    struct Coordinate {
        int x, y;
    };
    std::queue<Coordinate> q;

    bool color = image[x][y];
    q.push(Coordinate{ x,y });
    image[x][y] = !color;
    
    while(!q.empty()){
        Coordinate curr = q.front();
        std::array<std::array<int, 2>, 4> adjacent{ {{0,1}, {0,-1}, {1,0}, {-1,0}} };
        for (const std::array<int, 2>&d : adjacent) {
            Coordinate next = Coordinate{ curr.x + d[0], curr.y + d[1] };
            if (next.x >= 0 && next.x < image.size() && next.y >= 0 && next.y < image[next.x].size() &&
                image[next.x][next.y] == color) {
                image[next.x][next.y] = !color;
                q.push(next);
            }
        }
        q.pop();
    }
}

void FlipColorDFS(int x, int y, vector<deque<bool>>* image_ptr) {
    vector<deque<bool>>& image = *image_ptr;

    struct Coordinate {
        int x, y;
    };
    
    bool color = image[x][y];
    image[x][y] = !color;

    std::array<std::array<int, 2>, 4> adjacent{ {{0,1}, {0,-1}, {1,0}, {-1,0}} };
    for (const std::array<int, 2>&d : adjacent) {
        Coordinate next = Coordinate{ x + d[0], y + d[1] };
        if (next.x >= 0 && next.x < image.size() && next.y >= 0 && next.y < image[next.x].size() &&
            image[next.x][next.y] == color) {
            //image[next.x][next.y] = !color;
            FlipColorDFS(next.x, next.y, image_ptr);
        }
    }
}

void FlipColor(int x, int y, vector<deque<bool>>* image_ptr) {
    //FlipColorBFS(x, y, image_ptr);
    FlipColorDFS(x, y, image_ptr);
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
