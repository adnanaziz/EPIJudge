#include <vector>

#include "test_framework/test_utils_serialization_traits.h"

using std::vector;

struct Rectangle {
  int left, right, height;
};
typedef vector<Rectangle> Skyline;

Skyline ComputeSkyline(const vector<Rectangle>& buildings) {
  // Implement this placeholder.
  return {};
}

bool operator==(const Rectangle& a, const Rectangle& b) {
  return a.left == b.left && a.right == b.right && a.height == b.height;
}

template <>
struct SerializationTraits<Rectangle>
    : UserSerTraits<Rectangle, int, int, int> {};

std::ostream& operator<<(std::ostream& out, const Rectangle& r) {
  return EpiPrint(out, std::make_tuple(r.left, r.right, r.height));
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "drawing_skyline.tsv", &ComputeSkyline);
  return 0;
}
