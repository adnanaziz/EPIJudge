from typing import Iterator, List

from test_framework import generic_test, test_utils


# Finds the candidates which may occur > n / k times.
def search_frequent_items(k: int, stream: Iterator[str]) -> List[str]:
    # TODO - you fill in here.
    return []


def search_frequent_items_wrapper(k, stream):
    return search_frequent_items(k, iter(stream))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('search_frequent_items.py',
                                       'search_frequent_items.tsv',
                                       search_frequent_items_wrapper,
                                       test_utils.unordered_compare))
