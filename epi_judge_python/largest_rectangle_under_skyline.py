from typing import List

from test_framework import generic_test


def calculate_largest_rectangle(heights: List[int]) -> int:
    # TODO - you fill in here.
    return 0


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('largest_rectangle_under_skyline.py',
                                       'largest_rectangle_under_skyline.tsv',
                                       calculate_largest_rectangle))
