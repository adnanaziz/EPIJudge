from test_framework import generic_test


def is_even(x: int) -> bool:

    return not bool(x & 1)


if __name__ == '__main__':
    exit(generic_test.generic_test_main('is_even.py', 'is_even.tsv', is_even))
