from test_framework import generic_test


def gcd(x: int, y: int) -> int:

    if x > y:
        return gcd(y, x)
    elif x == 0:
        return y
    elif not x & 1 and not y & 1:  # x and y are even.
        return gcd(x >> 1, y >> 1) << 1
    elif not x & 1 and y & 1:  # x is even, y is odd.
        return gcd(x >> 1, y)
    elif x & 1 and not y & 1:  # x is odd, y is even.
        return gcd(x, y >> 1)
    return gcd(x, y - x)  # Both x and y are odd.


if __name__ == '__main__':
    exit(generic_test.generic_test_main('gcd.py', 'gcd.tsv', gcd))
