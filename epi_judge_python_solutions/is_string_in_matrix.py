import functools
from typing import List

from test_framework import generic_test


def is_pattern_contained_in_grid(grid: List[List[int]],
                                 pattern: List[int]) -> bool:
    @functools.lru_cache(None)
    def is_pattern_suffix_contained_starting_at_xy(x, y, offset):
        if len(pattern) == offset:
            # Nothing left to complete.
            return True

        # Early return if (x, y) lies outside the grid or the character
        # does not match or we have already tried this combination.
        if (not (0 <= x < len(grid) and 0 <= y < len(grid[x]))
                or grid[x][y] != pattern[offset]):
            return False

        return any(
            is_pattern_suffix_contained_starting_at_xy(*next_xy, offset + 1)
            for next_xy in ((x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)))

    return any(
        is_pattern_suffix_contained_starting_at_xy(i, j, offset=0)
        for i in range(len(grid)) for j in range(len(grid[i])))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('is_string_in_matrix.py',
                                       'is_string_in_matrix.tsv',
                                       is_pattern_contained_in_grid))
