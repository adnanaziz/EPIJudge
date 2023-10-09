from test_framework import generic_test


def parity(x: int) -> int:
    count = 0
    while x:
        count += x & 1
        x >>= 1
    if count % 2 != 0:
        return 1
    return 0


if __name__ == '__main__':
    exit(generic_test.generic_test_main('parity.py', 'parity.tsv', parity))
