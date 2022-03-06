#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
struct IteratorCurrentAndEnd {

    bool operator > (const IteratorCurrentAndEnd& that) const {
        return *current > *that.current;
    }

    vector<int>::const_iterator current;
    vector<int>::const_iterator end;
};

vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays) {
    std::priority_queue<IteratorCurrentAndEnd, vector<IteratorCurrentAndEnd>, std::greater<>> min_heap;

    for (const vector<int>& sorted_arr : sorted_arrays) {
        if(!sorted_arr.empty())
            min_heap.emplace(IteratorCurrentAndEnd{ sorted_arr.cbegin(), sorted_arr.cend()});
    }

    vector<int> results;
    while (!min_heap.empty()) {
        auto sorted_arr = min_heap.top();
        min_heap.pop();

        results.emplace_back(*sorted_arr.current);
            
        if(next(sorted_arr.current) != sorted_arr.end)
            min_heap.emplace(IteratorCurrentAndEnd{ next(sorted_arr.current), sorted_arr.end });
    }

    return results;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sorted_arrays"};
  return GenericTestMain(args, "sorted_arrays_merge.cc",
                         "sorted_arrays_merge.tsv", &MergeSortedArrays,
                         DefaultComparator{}, param_names);
}
