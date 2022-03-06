#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

vector<double> OnlineMedian(vector<int>::const_iterator sequence_begin,
                            const vector<int>::const_iterator& sequence_end) {
    std::priority_queue<int, vector<int>, std::greater<>> min_heap;
    std::priority_queue<int, vector<int>, std::less<>> max_heap;

    vector<double> results;

    while (sequence_begin != sequence_end) {
        int val = *sequence_begin;
        sequence_begin++;

        if (min_heap.empty())
            min_heap.emplace(val);
        else if (val >= min_heap.top())
            min_heap.emplace(val);
        else
            max_heap.emplace(val);

        if (min_heap.size() > max_heap.size() + 1) {
            max_heap.emplace(min_heap.top());
            min_heap.pop();
        }
        else if (max_heap.size() > min_heap.size()) {
            min_heap.emplace(max_heap.top());
            max_heap.pop();
        }

        double median = (max_heap.size() == min_heap.size()) ? (static_cast<double>(max_heap.top() + min_heap.top())) * 0.5 : min_heap.top();
        results.emplace_back(median);
    }

    return results;
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
