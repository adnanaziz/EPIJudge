import functools

from test_framework import generic_test


@functools.lru_cache(None)
def get_height(cases: int, drops: int) -> int:

    if cases == 0 or drops == 0:
        return 0
    elif cases == 1:
        return drops
    return get_height(cases, drops - 1) + get_height(cases - 1, drops - 1) + 1


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('max_safe_height.py',
                                       'max_safe_height.tsv', get_height))
