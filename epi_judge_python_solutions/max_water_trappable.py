from typing import List

from test_framework import generic_test


def calculate_trapping_water(heights: List[int]) -> int:

    # Finds the index with maximum height.
    max_h = heights.index(max(heights))

    # Assume heights[-1] is maximum height.
    def trapping_water_till_end(heights):
        partial_sum, highest_level_seen = 0, float('-inf')
        for h in heights:
            if h >= highest_level_seen:
                highest_level_seen = h
            else:
                partial_sum += highest_level_seen - h
        return partial_sum

    return (trapping_water_till_end(heights[:max_h]) +
            trapping_water_till_end(reversed(heights[max_h + 1:])))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('max_water_trappable.py',
                                       'max_water_trappable.tsv',
                                       calculate_trapping_water))
