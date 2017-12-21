def online_median(sequence):
    # Implement this placeholder.
    return []


def online_median_wrapper(sequence):
    return online_median(iter(sequence))


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main("online_median.tsv",
                                              online_median_wrapper)
