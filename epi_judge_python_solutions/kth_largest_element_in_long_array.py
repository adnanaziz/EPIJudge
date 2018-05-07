import heapq

from kth_largest_in_array import find_kth_largest
from test_framework import generic_test


def find_kth_largest_unknown_length(stream, k):

    candidates = []
    for x in stream:
        candidates.append(x)
        if len(candidates) >= 2 * k - 1:
            # Reorders elements about median with larger elements appearing
            # before the median.
            find_kth_largest(k, candidates)
            # Resize to keep just the k largest elements seen so far.
            del candidates[k:]
    # Finds the k-th largest element in candidates.
    find_kth_largest(k, candidates)
    return candidates[k - 1]


# Pythonic solution that uses library method but costs O(nlogk) time.
def find_kth_largest_unknown_length_pythonic(stream, k):
    return heapq.nlargest(k, stream)[-1]


def find_kth_largest_unknown_length_wrapper(stream, k):
    return find_kth_largest_unknown_length(iter(stream), k)


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            "kth_largest_element_in_long_array.py",
            'kth_largest_element_in_long_array.tsv',
            find_kth_largest_unknown_length_wrapper))
