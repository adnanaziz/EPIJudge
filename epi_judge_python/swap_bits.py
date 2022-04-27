from test_framework import generic_test


def swap_bits(x, i, j):
    lst = []

    return 0

def count_bits(x: int) -> int:
    ret = []
    while x > 0:
        if x % 2 == 1:
            ret += 1
        x //= 2
    return ret

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('swap_bits.py', 'swap_bits.tsv',
                                       swap_bits))
