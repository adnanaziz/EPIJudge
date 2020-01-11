#include <algorithm>
#include <cmath>
#include <functional>
#include <queue>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
#include "test_framework/test_utils.h"

using std::function;
using std::priority_queue;
using std::vector;

struct Star {
  bool operator<(const Star& that) const {
    return Distance() < that.Distance();
  }

  double Distance() const { return sqrt(x * x + y * y + z * z); }

  double x, y, z;
};

vector<Star> FindClosestKStars(vector<Star>::const_iterator stars_begin,
                               const vector<Star>::const_iterator& stars_end,
                               int k) {
  // max_heap to store the closest k stars seen so far.
  priority_queue<Star> max_heap;

  while (stars_begin != stars_end) {
    // Add each star to the max-heap. If the max-heap size exceeds k,
    // remove the maximum element from the max-heap.
    max_heap.emplace(*stars_begin++);
    if (size(max_heap) == k + 1) {
      max_heap.pop();
    }
  }

  // Iteratively extract from the max-heap, which yields the stars
  // sorted according from furthest to closest.
  vector<Star> closest_stars;
  while (!empty(max_heap)) {
    closest_stars.emplace_back(max_heap.top());
    max_heap.pop();
  }
  return {rbegin(closest_stars), rend(closest_stars)};
}

namespace test_framework {
template <>
struct SerializationTrait<Star> : UserSerTrait<Star, double, double, double> {};
}  // namespace test_framework

std::ostream& operator<<(std::ostream& out, const Star& s) {
  return out << s.Distance();
}

bool Comp(const vector<double>& expected, vector<Star> output) {
  if (output.size() != expected.size()) {
    return false;
  }

  std::sort(begin(output), end(output));

  for (int i = 0; i < output.size(); ++i) {
    if (!DefaultComparator()(output[i].Distance(), expected[i])) {
      return false;
    }
  }
  return true;
}

vector<Star> FindClosestKStarsWrapper(const vector<Star>& stars, int k) {
  return FindClosestKStars(cbegin(stars), cend(stars), k);
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"stars", "k"};
  return GenericTestMain(args, "k_closest_stars.cc", "k_closest_stars.tsv", &FindClosestKStarsWrapper,
                         &Comp, param_names);
}
// clang-format on
