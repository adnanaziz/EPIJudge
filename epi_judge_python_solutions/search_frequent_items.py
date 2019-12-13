import collections
import itertools
from typing import Counter, Iterator, List

from test_framework import generic_test, test_utils


# Finds the candidates which may occur > n / k times.
def search_frequent_items(k: int, stream: Iterator[str]) -> List[str]:

    stream, stream_copy = itertools.tee(stream)
    table: Counter[str] = collections.Counter()
    n = 0  # Count the number of strings.

    for buf in stream:
        table[buf] += 1
        n += 1
        # Detecting k items in table, at least one of them must have exactly
        # one in it. We will discard those k items by one for each.
        if len(table) == k:
            for it in table:
                table[it] -= 1
            table = +table  # Removes all zero values.

    # Resets table for the following counting.
    for it in table:
        table[it] = 0

    # Resets the stream and read it again.
    stream = stream_copy
    # Counts the occurrence of each candidate word.
    for buf in stream:
        if buf in table:
            table[buf] += 1

    # Selects the word which occurs > n / k times.
    return [it for it, value in table.items() if value > n / k]


def search_frequent_items_wrapper(k, stream):
    return search_frequent_items(k, iter(stream))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('search_frequent_items.py',
                                       'search_frequent_items.tsv',
                                       search_frequent_items_wrapper,
                                       test_utils.unordered_compare))
