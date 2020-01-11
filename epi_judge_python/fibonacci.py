from test_framework import generic_test


def fibonacci(n: int) -> int:
    # TODO - you fill in here.
    return -1


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('fibonacci.py', 'fibonacci.tsv',
                                       fibonacci))
