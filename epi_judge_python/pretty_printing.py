from typing import List

from test_framework import generic_test


def minimum_messiness(words: List[str], line_length: int) -> int:
    # TODO - you fill in here.
    return 0


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('pretty_printing.py',
                                       'pretty_printing.tsv',
                                       minimum_messiness))
