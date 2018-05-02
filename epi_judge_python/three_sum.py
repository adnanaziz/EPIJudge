from test_framework import generic_test


def has_three_sum(A, t):
    # TODO - you fill in here.
    return True


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("three_sum.py", "three_sum.tsv",
                                       has_three_sum))
