# gallons[i] is the amount of gas in city i, and distances[i] is the
# distance city i to the next city.
def find_ample_city(gallons, distances):
    # Implement this placeholder.
    return 0


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('refueling_schedule.tsv',
                                       find_ample_city))
