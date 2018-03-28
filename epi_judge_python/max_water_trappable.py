def calculate_trapping_water(heights):
    # Implement this placeholder.
    return 0


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('max_water_trappable.tsv',
                                       calculate_trapping_water))
