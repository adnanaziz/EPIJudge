from typing import List

from test_framework import generic_test


def justify_text(words: List[str], L: int) -> List[str]:
    # TODO - you fill in here.
    return []


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('left_right_justify_text.py',
                                       'left_right_justify_text.tsv',
                                       justify_text))
