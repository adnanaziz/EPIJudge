#include <vector>

#include "test_framework/test_utils_serialization_traits.h"

using std::vector;

struct Item {
  int weight, value;
};

int OptimumSubjectToCapacity(const vector<Item>& items, int capacity) {
  // Implement this placeholder.
  return 0;
}

template <>
struct SerializationTraits<Item> : UserSerTraits<Item, int, int> {};

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"items", "capacity"};
  generic_test_main(argc, argv, param_names, "knapsack.tsv",
                    &OptimumSubjectToCapacity);
  return 0;
}
