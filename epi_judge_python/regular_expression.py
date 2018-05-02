from test_framework import generic_test


def is_match(regex, s):
    # TODO - you fill in here.
    return True


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("regular_expression.py",
                                       'regular_expression.tsv', is_match))
