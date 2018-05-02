from test_framework import generic_test


def get_height(cases, drops):
    # TODO - you fill in here.
    return 0


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("max_safe_height.py",
                                       'max_safe_height.tsv', get_height))
