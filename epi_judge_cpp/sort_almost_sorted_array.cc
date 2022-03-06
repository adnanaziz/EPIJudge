#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> SortApproximatelySortedData(
    vector<int>::const_iterator sequence_begin,
    const vector<int>::const_iterator& sequence_end, int k) {
    
    std::priority_queue<int, vector<int>, std::greater<>> min_heap;
    vector<int>::const_iterator iter = sequence_begin;
    
    for (int count = 0; count < k && iter != sequence_end; iter++, count++)
        min_heap.emplace(*iter);

    vector<int> results;
    while (iter != sequence_end) {
        results.emplace_back(min_heap.top());
        min_heap.pop();
        min_heap.emplace(*iter);
        iter++;
    }
    
    while (!min_heap.empty()) {
        results.emplace_back(min_heap.top());
        min_heap.pop();
    }

    return results;
}
vector<int> SortApproximatelySortedDataWrapper(const vector<int>& sequence,
                                               int k) {
  return SortApproximatelySortedData(cbegin(sequence), cend(sequence), k);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sequence", "k"};
  return GenericTestMain(
      args, "sort_almost_sorted_array.cc", "sort_almost_sorted_array.tsv",
      &SortApproximatelySortedDataWrapper, DefaultComparator{}, param_names);
}
