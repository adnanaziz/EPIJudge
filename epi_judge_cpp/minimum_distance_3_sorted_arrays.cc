#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

struct IterItem{
    vector<int>::const_iterator iter, end;
};

int FindClosestElementsInSortedArrays(const vector<vector<int>>& sorted_arrays) {
    
    int min_so_far = std::numeric_limits<int>::max();
    std::multimap<int, IterItem> values;

    for (auto& sorted_array : sorted_arrays) {
        values.emplace(sorted_array.front(), IterItem{sorted_array.cbegin(), sorted_array.cend()});
    }

    while (true) {
        auto min_val = values.cbegin()->first;
        auto max_val = values.crbegin()->first;

        min_so_far = std::min(min_so_far, max_val - min_val);
        auto iter_next = next(values.cbegin()->second.iter);
        auto iter_end = values.cbegin()->second.end;

        if (iter_next == iter_end)
            return min_so_far;

        IterItem new_iter { iter_next, values.cbegin()->second.end};

        values.emplace(*iter_next, new_iter);
        values.erase(values.cbegin());
    }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sorted_arrays"};
  return GenericTestMain(args, "minimum_distance_3_sorted_arrays.cc",
                         "minimum_distance_3_sorted_arrays.tsv",
                         &FindClosestElementsInSortedArrays,
                         DefaultComparator{}, param_names);
}
