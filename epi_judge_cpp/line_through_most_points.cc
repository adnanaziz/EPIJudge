#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;

struct Point {
  int x, y;
};
int FindLineWithMostPoints(const vector<Point>& points) {
  // TODO - you fill in here.
  return 0;
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
