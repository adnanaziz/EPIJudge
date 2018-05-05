#include <vector>
#include "test_framework/fmt_print.h"
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;

struct Rectangle {
  int left, right, height;
};
typedef vector<Rectangle> Skyline;

Skyline ComputeSkyline(const vector<Rectangle>& buildings) {
  // TODO - you fill in here.
  return {};
}
bool operator==(const Rectangle& a, const Rectangle& b) {
  return a.left == b.left && a.right == b.right && a.height == b.height;
}
}  // namespace drawing_skyline

using drawing_skyline::ComputeSkyline;

template <>
struct SerializationTraits<drawing_skyline::Rectangle>
    : UserSerTraits<drawing_skyline::Rectangle, int, int, int> {};

std::ostream& operator<<(std::ostream& out,
                         const drawing_skyline::Rectangle& r) {
  return PrintTo(out, std::make_tuple(r.left, r.right, r.height));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"buildings"};
  return GenericTestMain(args, "drawing_skyline.cc", "drawing_skyline.tsv",
                         &ComputeSkyline, DefaultComparator{}, param_names);
}
