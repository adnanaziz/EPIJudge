from test_framework import generic_test


def minimum_total_waiting_time(service_times):
    # TODO - you fill in here.
    return 0


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("minimum_waiting_time.py",
                                       'minimum_waiting_time.tsv',
                                       minimum_total_waiting_time))
