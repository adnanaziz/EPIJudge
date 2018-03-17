#include <vector>

#include "test_framework/generic_test.h"
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

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"points"};
  return GenericTestMain(args, timeout_seconds, "line_though_most_points.tsv",
                         &FindLineWithMostPoints, DefaultComparator{},
                         param_names);
}
