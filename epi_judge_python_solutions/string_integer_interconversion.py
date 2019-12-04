from test_framework import generic_test
from test_framework.test_failure import TestFailure


def int_to_string(x):

    is_negative = False
    if x < 0:
        x, is_negative = -x, True

    s = []
    while True:
        s.append(chr(ord('0') + x % 10))
        x //= 10
        if x == 0:
            break

    # Adds the negative sign back if is_negative
    if is_negative:
        s.append('-')
    return ''.join(reversed(s))


def string_to_int(s):
    import functools
    import string
    return functools.reduce(
        lambda running_sum, c: running_sum * 10 + string.digits.index(c),
        s[s[0] in {'+', '-'}:], 0) * (-1 if s[0] == '-' else 1)


def wrapper(x, s):
    if int(int_to_string(x)) != int(s):
        raise TestFailure("Int to string conversion failed")
    if string_to_int(s) != x:
        raise TestFailure("String to int conversion failed")


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("string_integer_interconversion.py",
                                       'string_integer_interconversion.tsv',
                                       wrapper))
