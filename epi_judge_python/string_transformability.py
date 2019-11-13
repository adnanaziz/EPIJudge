from typing import Set

from test_framework import generic_test


def transform_string(D: Set[str], s: str, t: str) -> int:
    # TODO - you fill in here.
    return 0


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('string_transformability.py',
                                       'string_transformability.tsv',
                                       transform_string))
