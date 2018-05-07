from test_framework import generic_test

cache = {}


def fibonacci(n):

    if n <= 1:
        return n
    elif n not in cache:
        cache[n] = fibonacci(n - 1) + fibonacci(n - 2)
    return cache[n]


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("fibonacci.py", 'fibonacci.tsv',
                                       fibonacci))
