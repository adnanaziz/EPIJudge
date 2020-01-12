from typing import Iterator

from test_framework import generic_test


def find_kth_largest_unknown_length(stream: Iterator[int], k: int) -> int:
    # TODO - you fill in here.
    return 0


# Pythonic solution that uses library method but costs O(nlogk) time.
def find_kth_largest_unknown_length_pythonic(stream, k):
    return heapq.nlargest(k, stream)[-1]


def find_kth_largest_unknown_length_wrapper(stream, k):
    return find_kth_largest_unknown_length(iter(stream), k)


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            'kth_largest_element_in_long_array.py',
            'kth_largest_element_in_long_array.tsv',
            find_kth_largest_unknown_length_wrapper))
