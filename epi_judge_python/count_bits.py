from test_framework import generic_test


def count_bits(x: int) -> int:
    # TODO - you fill in here.
    ret = 0
    while x > 0:
        if x % 2 == 1:
            ret += 1
        x //= 2
    return ret


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('count_bits.py', 'count_bits.tsv',
                                       count_bits))
