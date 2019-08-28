from typing import Iterator, List

from test_framework import generic_test


def examine_buildings_with_sunset(sequence: Iterator[int]) -> List[int]:
    # TODO - you fill in here.
    return []


def examine_buildings_with_sunset_wrapper(sequence):
    return examine_buildings_with_sunset(iter(sequence))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('sunset_view.py', 'sunset_view.tsv',
                                       examine_buildings_with_sunset))
