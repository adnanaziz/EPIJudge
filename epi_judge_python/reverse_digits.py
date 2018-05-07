from test_framework import generic_test


def reverse(x):
    # TODO - you fill in here.
    return 0


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("reverse_digits.py",
                                       'reverse_digits.tsv', reverse))
