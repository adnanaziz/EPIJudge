import functools

from test_framework import generic_test


def smallest_nonconstructible_value(A):

    max_constructible_value = 0
    for a in sorted(A):
        if a > max_constructible_value + 1:
            break
        max_constructible_value += a
    return max_constructible_value + 1


def smallest_nonconstructible_value_pythonic(A):
    return functools.reduce(
        lambda max_val, a: max_val + (0 if a > max_val + 1 else a), sorted(A),
        0) + 1


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("smallest_nonconstructible_value.py",
                                       'smallest_nonconstructible_value.tsv',
                                       smallest_nonconstructible_value))
