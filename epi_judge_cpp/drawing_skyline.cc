#include <vector>
#include "test_framework/fmt_print.h"
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;

struct Rect {
  int left, right, height;
};
typedef vector<Rect> Skyline;

Skyline ComputeSkyline(const vector<Rect>& buildings) {
  // TODO - you fill in here.
  return {};
}
bool operator==(const Rect& a, const Rect& b) {
  return a.left == b.left && a.right == b.right && a.height == b.height;
}

template <>
struct SerializationTraits<Rect> : UserSerTraits<Rect, int, int, int> {};

std::ostream& operator<<(std::ostream& out, const Rect& r) {
  return PrintTo(out, std::make_tuple(r.left, r.right, r.height));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"buildings"};
  return GenericTestMain(args, "drawing_skyline.cc", "drawing_skyline.tsv",
                         &ComputeSkyline, DefaultComparator{}, param_names);
}
