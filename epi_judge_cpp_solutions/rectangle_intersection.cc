#include <algorithm>
#include <tuple>

#include "test_framework/fmt_print.h"
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"

using std::max;
using std::min;

namespace rectangle_intersection {
struct Rectangle;

bool IsIntersect(const Rectangle&, const Rectangle&);

struct Rectangle {
  int x, y, width, height;
};

Rectangle IntersectRectangle(const Rectangle& R1, const Rectangle& R2) {
  if (!IsIntersect(R1, R2)) {
    return {0, 0, -1, -1};  // No intersection.
  }
  return {max(R1.x, R2.x), max(R1.y, R2.y),
          min(R1.x + R1.width, R2.x + R2.width) - max(R1.x, R2.x),
          min(R1.y + R1.height, R2.y + R2.height) - max(R1.y, R2.y)};
}

bool IsIntersect(const Rectangle& R1, const Rectangle& R2) {
  return R1.x <= R2.x + R2.width && R1.x + R1.width >= R2.x &&
         R1.y <= R2.y + R2.height && R1.y + R1.height >= R2.y;
}

bool operator==(const Rectangle& r1, const Rectangle& r2) {
  return std::tie(r1.x, r1.y, r1.width, r1.height) ==
         std::tie(r2.x, r2.y, r2.width, r2.height);
}

}  // namespace rectangle_intersection

using rectangle_intersection::IntersectRectangle;

template <>
struct SerializationTraits<rectangle_intersection::Rectangle>
    : UserSerTraits<rectangle_intersection::Rectangle, int, int, int, int> {
  static std::vector<std::string> GetMetricNames(const std::string& arg_name) {
    return {FmtStr("area({})", arg_name), FmtStr("perimeter({})", arg_name),
            FmtStr("max(w, h)({})", arg_name)};
  }

  static std::vector<int> GetMetrics(
      const rectangle_intersection::Rectangle& x) {
    return {x.height * x.width, 2 * (x.height + x.width),
            std::max(x.height, x.width)};
  }
};

std::ostream& operator<<(std::ostream& out,
                         const rectangle_intersection::Rectangle& r) {
  return PrintTo(out, std::make_tuple(r.x, r.y, r.width, r.height));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"R1", "R2"};
  return GenericTestMain(args, "rectangle_intersection.cc",
                         "rectangle_intersection.tsv", &IntersectRectangle,
                         DefaultComparator{}, param_names);
}
