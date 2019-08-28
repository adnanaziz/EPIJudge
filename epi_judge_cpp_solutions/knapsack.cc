#include <algorithm>
#include <iterator>
#include <memory>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"

using std::make_unique;
using std::max;
using std::min;
using std::vector;

struct Item;
int OptimumSubjectToItemAndCapacity(const vector<Item>&, int, int,
                                    vector<vector<int>>*);

struct Item {
  int weight, value;
};

int OptimumSubjectToCapacity(const vector<Item>& items, int capacity) {
  return OptimumSubjectToItemAndCapacity(
      items, size(items) - 1, capacity,
      make_unique<vector<vector<int>>>(size(items),
                                       vector<int>(capacity + 1, -1))
          .get());
}

// Returns the optimum value when we choose from items[0, k] and have a
// capacity of available_capacity.
int OptimumSubjectToItemAndCapacity(const vector<Item>& items, int k,
                                    int available_capacity,
                                    vector<vector<int>>* V_ptr) {
  if (k < 0) {
    // No items can be chosen.
    return 0;
  }

  // V[i][j] holds the optimum value when we choose from items[0, i] and have
  // a capacity of j.
  vector<vector<int>>& V = *V_ptr;
  if (V[k][available_capacity] == -1) {
    int without_curr_item = OptimumSubjectToItemAndCapacity(
        items, k - 1, available_capacity, V_ptr);
    int with_curr_item =
        available_capacity < items[k].weight
            ? 0
            : items[k].value + OptimumSubjectToItemAndCapacity(
                                   items, k - 1,
                                   available_capacity - items[k].weight, V_ptr);
    V[k][available_capacity] = max(without_curr_item, with_curr_item);
  }
  return V[k][available_capacity];
}

namespace test_framework {
template <>
struct SerializationTrait<Item> : UserSerTrait<Item, int, int> {};
}  // namespace test_framework

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"items", "capacity"};
  return GenericTestMain(args, "knapsack.cc", "knapsack.tsv",
                         &OptimumSubjectToCapacity, DefaultComparator{},
                         param_names);
}
