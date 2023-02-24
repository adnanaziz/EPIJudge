from test_framework import generic_test


def collatz_conjecture(n: int) -> bool:
    # TODO - you fill in here.
    return False


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('collatz_checker.py',
                                       'collatz_checker.tsv',
                                       collatz_conjecture))
