from test_framework import generic_test


def parity(x: int) -> int:
    result = 0 
    while x:
      result ^= 1 
      x &= (x-1)
    return result 


if __name__ == '__main__':
    exit(generic_test.generic_test_main('parity.py', 'parity.tsv', parity))
