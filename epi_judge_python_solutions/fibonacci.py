import functools

from test_framework import generic_test


@functools.lru_cache(None)
def fibonacci(n: int) -> int:

    return n if n <= 1 else fibonacci(n - 1) + fibonacci(n - 2)


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('fibonacci.py', 'fibonacci.tsv',
                                       fibonacci))
