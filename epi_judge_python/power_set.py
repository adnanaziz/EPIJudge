from typing import List

from test_framework import generic_test, test_utils


def generate_power_set(input_set: List[int]) -> List[List[int]]:
    # TODO - you fill in here.
    return []


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('power_set.py', 'power_set.tsv',
                                       generate_power_set,
                                       test_utils.unordered_compare))
