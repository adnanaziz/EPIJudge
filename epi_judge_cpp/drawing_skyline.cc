#include <vector>

#include "test_framework/fmt_print.h"
#include "test_framework/generic_test.h"
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
  return PrintTo(out, std::make_tuple(r.left, r.right, r.height));
}

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"buildings"};
  return GenericTestMain(args, timeout_seconds, "drawing_skyline.tsv",
                         &ComputeSkyline, DefaultComparator{}, param_names);
}
