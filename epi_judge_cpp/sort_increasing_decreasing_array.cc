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
        if (!sorted_arr.empty())
            min_heap.emplace(IteratorCurrentAndEnd{ sorted_arr.cbegin(), sorted_arr.cend() });
    }

    vector<int> results;
    while (!min_heap.empty()) {
        auto sorted_arr = min_heap.top();
        min_heap.pop();

        results.emplace_back(*sorted_arr.current);

        if (next(sorted_arr.current) != sorted_arr.end)
            min_heap.emplace(IteratorCurrentAndEnd{ next(sorted_arr.current), sorted_arr.end });
    }

    return results;
}

vector<int> SortKIncreasingDecreasingArray(const vector<int>& A) {
    vector<vector<int>> sort_arrays;
    typedef enum { INCREASING, DECREASING } SortDirection;

    int strt_indx = 0;
    SortDirection sort_direction = INCREASING;

    for (int i = 1; i <= A.size(); i++) {
        if (i == A.size() || 
            (A[i-1] > A[i] && sort_direction == INCREASING) || 
            (A[i-1] <= A[i] && sort_direction == DECREASING)) {
                
            if (sort_direction == INCREASING) {
                sort_arrays.emplace_back(A.cbegin()+strt_indx, A.cbegin() + i);
            }
            else {
                sort_arrays.emplace_back(A.crbegin() + A.size() - i, A.crbegin() + A.size()  - strt_indx);
            }

            sort_direction = (sort_direction == INCREASING) ? DECREASING : INCREASING;
            strt_indx = i;
        }
            
    }
    
    return MergeSortedArrays(sort_arrays);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "sort_increasing_decreasing_array.cc",
                         "sort_increasing_decreasing_array.tsv",
                         &SortKIncreasingDecreasingArray, DefaultComparator{},
                         param_names);
}
