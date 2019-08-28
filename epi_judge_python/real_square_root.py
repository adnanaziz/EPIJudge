from test_framework import generic_test


def square_root(x: float) -> float:
    # TODO - you fill in here.
    return 0.0


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('real_square_root.py',
                                       'real_square_root.tsv', square_root))
