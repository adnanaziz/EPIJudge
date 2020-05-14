from typing import List

from test_framework import generic_test


def expression_synthesis(digits: List[int], target: int) -> bool:
    # TODO - you fill in here.
    return True


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('insert_operators_in_string.py',
                                       'insert_operators_in_string.tsv',
                                       expression_synthesis))
