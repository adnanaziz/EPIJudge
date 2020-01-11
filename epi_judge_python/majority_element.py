from typing import Iterator

from test_framework import generic_test


def majority_search(stream: Iterator[str]) -> str:
    # TODO - you fill in here.
    return ''


def majority_search_wrapper(stream):
    return majority_search(iter(stream))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('majority_element.py',
                                       'majority_element.tsv',
                                       majority_search_wrapper))
