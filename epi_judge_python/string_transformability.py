from test_framework import generic_test


# Uses BFS to find the least steps of transformation.
def transform_string(D, s, t):
    # TODO - you fill in here.
    return 0


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("string_transformability.py",
                                       'string_transformability.tsv',
                                       transform_string))
