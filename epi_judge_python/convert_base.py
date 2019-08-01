from test_framework import generic_test

import string
import functools


def construct_from_base(num_as_int, base):
    return ('' if num_as_int == 0 else construct_from_base(num_as_int // base, base) + string.hexdigits[
        num_as_int % base].upper())


def convert_base(num_as_string, b1, b2):
    is_negative = 1 if num_as_string[0] == '-' else 0
    digits = [string.hexdigits.index(c.lower()) for c in num_as_string[is_negative:]]
    num_as_int = 0
    for d in digits:
        num_as_int = num_as_int * b1 + d

    b2_digits = []
    c = num_as_int
    while c:
        b2_digits.append(string.hexdigits[c % b2].upper())
        c //= b2
    num_as_string_b2 = ''.join(reversed(b2_digits))

    return ('-' if is_negative else '') + ('0' if num_as_int == 0 else num_as_string_b2)


def _convert_base(num_as_string, b1, b2):
    is_negative = num_as_string[0] == '-'
    num_as_int = functools.reduce(
        lambda x, c: x * b1 + string.hexdigits.index(c.lower()),
        num_as_string[is_negative:], 0
    )
    return ('-' if is_negative else '') + ('0' if num_as_int == 0 else construct_from_base(num_as_int, b2))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("convert_base.py", "convert_base.tsv",
                                       convert_base))
