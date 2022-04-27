from test_framework import generic_test

# Basically it's asking to see parity of a given number

def parity(x: int) -> int:
    x = count_bits(x)
    return x % 2

def count_bits(x: int) -> int:
    ret = 0
    while x > 0:
        if x % 2 == 1:
            ret += 1
        x //= 2
    return ret

if __name__ == '__main__':
    exit(generic_test.generic_test_main('parity.py', 'parity.tsv', parity))
