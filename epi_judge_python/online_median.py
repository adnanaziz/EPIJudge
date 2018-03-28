def online_median(sequence):
    # Implement this placeholder.
    return []


def online_median_wrapper(sequence):
    return online_median(iter(sequence))


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("online_median.tsv",
                                       online_median_wrapper))
