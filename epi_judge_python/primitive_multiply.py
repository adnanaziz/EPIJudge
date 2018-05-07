from test_framework import generic_test


def multiply(x, y):
    # TODO - you fill in here.
    return 0


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("primitive_multiply.py",
                                       'primitive_multiply.tsv', multiply))
