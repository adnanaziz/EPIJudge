import heapq
from typing import List

from test_framework import generic_test, test_utils


def k_largest_in_binary_heap(A: List[int], k: int) -> List[int]:

    if k <= 0:
        return []

    # Stores the (-value, index)-pair in candidate_max_heap. This heap is
    # ordered by value field. Uses the negative of value to get the effect of
    # a max heap.
    candidate_max_heap = []
    # The largest element in A is at index 0.
    candidate_max_heap.append((-A[0], 0))
    result = []
    for _ in range(k):
        candidate_idx = candidate_max_heap[0][1]
        result.append(-heapq.heappop(candidate_max_heap)[0])

        left_child_idx = 2 * candidate_idx + 1
        if left_child_idx < len(A):
            heapq.heappush(candidate_max_heap,
                           (-A[left_child_idx], left_child_idx))
        right_child_idx = 2 * candidate_idx + 2
        if right_child_idx < len(A):
            heapq.heappush(candidate_max_heap,
                           (-A[right_child_idx], right_child_idx))
    return result


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            'k_largest_in_heap.py',
            'k_largest_in_heap.tsv',
            k_largest_in_binary_heap,
            comparator=test_utils.unordered_compare))
