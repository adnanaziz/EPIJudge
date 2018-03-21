def can_reach_end(A):
    # Implement this placeholder.
    return True


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("advance_by_offsets.tsv",
                                       can_reach_end))
