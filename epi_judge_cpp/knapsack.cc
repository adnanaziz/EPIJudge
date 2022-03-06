#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;

struct Item {
  int weight, value;
};

int OptimumSubjectToValueAndCapacity(const vector<Item>& items, int k,  
                                     int adjusted_capacity, vector<vector<int>>& v) {
    if (k < 0)
        return 0;
    
    if(v[k][adjusted_capacity] == -1){
        int without_y = OptimumSubjectToValueAndCapacity(items, k - 1, adjusted_capacity, v);
        int with_y = adjusted_capacity - items[k].weight < 0? 0 : items[k].value + OptimumSubjectToValueAndCapacity(items, k - 1,  
                                                                                                   adjusted_capacity - items[k].weight, v);
        v[k][adjusted_capacity] = std::max(without_y , with_y);
    }

    return v[k][adjusted_capacity];
}

int OptimumSubjectToCapacity(const vector<Item>& items, int capacity) {
    
    vector<vector<int>> v(items.size(), vector<int>(capacity+1, -1));
    return OptimumSubjectToValueAndCapacity(items, items.size()-1, capacity, v);
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
