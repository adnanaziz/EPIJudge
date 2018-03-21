def examine_buildings_with_sunset(sequence):
    # Implement this placeholder.
    return []


def examine_buildings_with_sunset_wrapper(sequence):
    return examine_buildings_with_sunset(iter(sequence))


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('sunset_view.tsv',
                                       examine_buildings_with_sunset))
