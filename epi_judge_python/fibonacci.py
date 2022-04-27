from test_framework import generic_test


memo = {}

def fibonacci(n: int) -> int:
    if n < 1:
        return 0
    elif n <= 2:
        return 1
    if n in memo:
        return memo[n]
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2)
    return memo[n]


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('fibonacci.py', 'fibonacci.tsv',
                                       fibonacci))
