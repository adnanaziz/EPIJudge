from typing import List

from test_framework import generic_test


def get_max_trapped_water(heights: List[int]) -> int:

    i, j, max_water = 0, len(heights) - 1, 0
    while i < j:
        width = j - i
        max_water = max(max_water, width * min(heights[i], heights[j]))
        if heights[i] > heights[j]:
            j -= 1
        else:  # heights[i] <= heights[j].
            i += 1
    return max_water


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('max_trapped_water.py',
                                       'max_trapped_water.tsv',
                                       get_max_trapped_water))
