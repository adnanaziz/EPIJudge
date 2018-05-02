#include <initializer_list>
#include <istream>
#include <string>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

using std::vector;

typedef enum { kWhite, kBlack } Color;

struct Coordinate;
bool SearchMazeHelper(const Coordinate&, const Coordinate&,
                      vector<vector<Color>>*, vector<Coordinate>*);
bool IsFeasible(const Coordinate&, const vector<vector<Color>>&);

struct Coordinate {
  bool operator==(const Coordinate& that) const {
    return x == that.x && y == that.y;
  }

  int x, y;
};

vector<Coordinate> SearchMaze(vector<vector<Color>> maze, const Coordinate& s,
                              const Coordinate& e) {
  vector<Coordinate> path;
  SearchMazeHelper(s, e, &maze, &path);
  return path;
}

// Perform DFS to find a feasible path.
bool SearchMazeHelper(const Coordinate& cur, const Coordinate& e,
                      vector<vector<Color>>* maze_ptr,
                      vector<Coordinate>* path_ptr) {
  auto& maze = *maze_ptr;
  // Checks cur is within maze and is a white pixel.
  if (cur.x < 0 || cur.x >= size(maze) || cur.y < 0 ||
      cur.y >= size(maze[cur.x]) || maze[cur.x][cur.y] != kWhite) {
    return false;
  }
  auto& path = *path_ptr;
  path.emplace_back(cur);
  maze[cur.x][cur.y] = kBlack;
  if (cur == e) {
    return true;
  }

  for (const Coordinate& next_move :
       {Coordinate{cur.x, cur.y + 1}, Coordinate{cur.x, cur.y - 1},
        Coordinate{cur.x + 1, cur.y}, Coordinate{cur.x - 1, cur.y}}) {
    if (SearchMazeHelper(next_move, e, maze_ptr, path_ptr)) {
      return true;
    }
  }
  // Cannot find a path, remove the entry added in path.emplace_back(cur).
  path.pop_back();
  return false;
}

template <>
struct SerializationTraits<Color> : SerializationTraits<int> {
  using serialization_type = Color;

  static serialization_type Parse(const std::string& str) {
    return static_cast<serialization_type>(
        SerializationTraits<int>::Parse(str));
  }

  static serialization_type JsonParse(const json_parser::Json& json_object) {
    return static_cast<serialization_type>(
        SerializationTraits<int>::JsonParse(json_object));
  }
};

template <>
struct SerializationTraits<Coordinate> : UserSerTraits<Coordinate, int, int> {
  static std::vector<std::string> GetMetricNames(const std::string& arg_name) {
    return {};
  }

  static std::vector<int> GetMetrics(const Coordinate& x) { return {}; }
};

bool PathElementIsFeasible(const vector<vector<Color>>& maze,
                           const Coordinate& prev, const Coordinate& cur) {
  if (!(0 <= cur.x && cur.x < maze.size() && 0 <= cur.y &&
        cur.y < maze[cur.x].size() && maze[cur.x][cur.y] == kWhite)) {
    return false;
  }
  return cur == Coordinate{prev.x + 1, prev.y} ||
         cur == Coordinate{prev.x - 1, prev.y} ||
         cur == Coordinate{prev.x, prev.y + 1} ||
         cur == Coordinate{prev.x, prev.y - 1};
}

bool SearchMazeWrapper(TimedExecutor& executor,
                       const vector<vector<Color>>& maze, const Coordinate& s,
                       const Coordinate& e) {
  vector<vector<Color>> copy = maze;

  auto path = executor.Run([&] { return SearchMaze(copy, s, e); });

  if (path.empty()) {
    return s == e;
  }

  if (!(path.front() == s) || !(path.back() == e)) {
    throw TestFailure("Path doesn't lay between start and end points");
  }

  for (size_t i = 1; i < path.size(); i++) {
    if (!PathElementIsFeasible(maze, path[i - 1], path[i])) {
      throw TestFailure("Path contains invalid segments");
    }
  }

  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "maze", "s", "e"};
  return GenericTestMain(args, "search_maze.cc", "search_maze.tsv",
                         &SearchMazeWrapper, DefaultComparator{}, param_names);
}
