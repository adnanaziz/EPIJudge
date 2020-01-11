from typing import List

from test_framework import generic_test


def calculate_bonus(productivity: List[int]) -> int:
    # TODO - you fill in here.
    return 0


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('bonus.py', 'bonus.tsv',
                                       calculate_bonus))
