def minimum_total_waiting_time(service_times):
    # Implement this placeholder.
    return 0


from sys import exit

from test_framework import generic_test, test_utils

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('minimum_waiting_time.tsv',
                                       minimum_total_waiting_time))
