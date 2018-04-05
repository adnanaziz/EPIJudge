def parity(x):
    result = 0
    while x:
        result ^= x & 1
        x >>= 1
    return result


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(generic_test.generic_test_main('parity.tsv', parity))
