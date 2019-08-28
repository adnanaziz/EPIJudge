from typing import List

from test_framework import generic_test, test_utils


def find_anagrams(dictionary: List[str]) -> List[List[str]]:
    # TODO - you fill in here.
    return []


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main(
            'anagrams.py',
            'anagrams.tsv',
            find_anagrams,
            comparator=test_utils.unordered_compare))
