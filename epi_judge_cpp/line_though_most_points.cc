#include <vector>

#include "test_framework/test_utils_serialization_traits.h"

using std::vector;

struct Point {
  int x, y;
};

int FindLineWithMostPoints(const vector<Point>& points) {
  // Implement this placeholder.
  return 0;
}

template <>
struct SerializationTraits<Point> : UserSerTraits<Point, int, int> {};

bool operator==(const Point& lhs, const Point& rhs) {
  return std::tie(lhs.x, lhs.y) == std::tie(rhs.x, rhs.y);
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"points"};
  GenericTestMain(args, "line_though_most_points.tsv", &FindLineWithMostPoints,
                  DefaultComparator{}, param_names);
  return 0;
}
