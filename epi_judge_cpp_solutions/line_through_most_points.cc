#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <utility>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"

using std::hash;
using std::max;
using std::max_element;
using std::pair;
using std::unordered_map;
using std::vector;

struct Point {
  int x, y;
};

int FindLineWithMostPoints(const vector<Point>& points) {
  // Hash function for a pair.
  struct HashPair {
    size_t operator()(const pair<int, int>& p) const {
      return static_cast<size_t>(31) * p.first + p.second;
    }
  };

  int result = 0;
  for (int i = 0; i < size(points); ++i) {
    unordered_map<pair<int, int>, int, HashPair> slope_table;
    int overlap_points = 1;
    for (int j = i + 1; j < size(points); ++j) {
      if (points[i].x == points[j].x && points[i].y == points[j].y) {
        ++overlap_points;
      } else {
        if (int x_diff = points[i].x - points[j].x,
            y_diff = points[i].y - points[j].y;
            x_diff == 0) {
          // A vertical line with slope 1/0.
          slope_table[{x_diff, 1}] += 1;
        } else {
          int gcd = std::gcd(x_diff, y_diff);
          x_diff /= gcd, y_diff /= gcd;
          if (x_diff < 0) {
            x_diff = -x_diff, y_diff = -y_diff;
          }
          slope_table[{x_diff, y_diff}] += 1;
        }
      }
    }
    result =
        max(result, overlap_points +
                        (empty(slope_table)
                             ? 0
                             : max_element(begin(slope_table), end(slope_table),
                                           [](const auto& a, const auto& b) {
                                             return a.second < b.second;
                                           })
                                   ->second));
  }
  return result;
}

namespace test_framework {
template <>
struct SerializationTrait<Point> : UserSerTrait<Point, int, int> {};
}  // namespace test_framework
bool operator==(const Point& lhs, const Point& rhs) {
  return std::tie(lhs.x, lhs.y) == std::tie(rhs.x, rhs.y);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"points"};
  return GenericTestMain(
      args, "line_through_most_points.cc", "line_through_most_points.tsv",
      &FindLineWithMostPoints, DefaultComparator{}, param_names);
}
