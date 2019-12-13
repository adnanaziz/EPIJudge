import functools

from test_framework import generic_test


@functools.lru_cache(None)
def fibonacci(n: int) -> int:

    if n <= 1:
        return n
    return fibonacci(n - 1) + fibonacci(n - 2)


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('fibonacci.py', 'fibonacci.tsv',
                                       fibonacci))
