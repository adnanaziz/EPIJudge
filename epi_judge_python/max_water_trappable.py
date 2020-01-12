from typing import List

from test_framework import generic_test


def calculate_trapping_water(heights: List[int]) -> int:
    # TODO - you fill in here.
    return 0


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('max_water_trappable.py',
                                       'max_water_trappable.tsv',
                                       calculate_trapping_water))
