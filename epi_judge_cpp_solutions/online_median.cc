#include <functional>
#include <queue>
#include <vector>

#include "test_framework/generic_test.h"

using std::greater;
using std::less;
using std::priority_queue;
using std::vector;

vector<double> OnlineMedian(vector<int>::const_iterator sequence_begin,
                            const vector<int>::const_iterator& sequence_end) {
  // min_heap stores the larger half seen so far.
  priority_queue<int, vector<int>, greater<>> min_heap;
  // max_heap stores the smaller half seen so far.
  priority_queue<int, vector<int>, less<>> max_heap;
  vector<double> result;

  while (sequence_begin != sequence_end) {
    min_heap.emplace(*sequence_begin++);
    max_heap.emplace(min_heap.top());
    min_heap.pop();
    // Ensure min_heap and max_heap have equal number of elements if
    // an even number of elements is read; otherwise, min_heap must have
    // one more element than max_heap.
    if (size(max_heap) > size(min_heap)) {
      min_heap.emplace(max_heap.top());
      max_heap.pop();
    }

    result.emplace_back(size(min_heap) == size(max_heap)
                            ? 0.5 * (min_heap.top() + max_heap.top())
                            : min_heap.top());
  }
  return result;
}

vector<double> OnlineMedianWrapper(const vector<int>& sequence) {
  return OnlineMedian(cbegin(sequence), cend(sequence));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sequence"};
  return GenericTestMain(args, "online_median.cc", "online_median.tsv",
                         &OnlineMedianWrapper, DefaultComparator{},
                         param_names);
}
