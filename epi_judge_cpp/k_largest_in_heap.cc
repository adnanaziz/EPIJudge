#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

struct HeapNode {
    bool operator < (const HeapNode& that) {
        return value < that.value;
    }

    int value;
    int index;
};

vector<int> KLargestInBinaryHeap(const vector<int>& A, int k) {
    std::priority_queue<HeapNode, vector<HeapNode>, std::less<>> max_heap;

    max_heap.emplace(HeapNode{A[0], 0});

    vector<int> results;
    for (int i = 0; i < k; i++) {
        HeapNode node = max_heap.top();

        results.emplace_back(node.value);
        int considered_index = node.index;
        
        max_heap.pop();

        int left_child = considered_index * 2 + 1;
        if (left_child < A.size()) {
            max_heap.emplace(HeapNode{ A[left_child], left_child });
        }
        
        int right_child = considered_index * 2 + 2;
        if (right_child < A.size()) {
            max_heap.emplace(HeapNode{ A[right_child], right_child });
        }

    }

    return results;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "k"};
  return GenericTestMain(args, "k_largest_in_heap.cc", "k_largest_in_heap.tsv",
                         &KLargestInBinaryHeap, UnorderedComparator{},
                         param_names);
}
