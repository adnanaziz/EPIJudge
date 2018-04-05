#include <algorithm>
#include <tuple>

#include "test_framework/fmt_print.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_utils_serialization_traits.h"

using std::max;
using std::min;

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

template <>
struct SerializationTraits<Rectangle>
    : UserSerTraits<Rectangle, int, int, int, int> {};

std::ostream& operator<<(std::ostream& out, const Rectangle& r) {
  return PrintTo(out, std::make_tuple(r.x, r.y, r.width, r.height));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"R1", "R2"};
  return GenericTestMain(args, "rectangle_intersection.tsv",
                         &IntersectRectangle, DefaultComparator{}, param_names);
}
