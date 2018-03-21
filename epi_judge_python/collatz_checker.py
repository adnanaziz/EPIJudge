def test_collatz_conjecture(n):
    # Implement this placeholder.
    return False


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('collatz_checker.tsv',
                                       test_collatz_conjecture))
