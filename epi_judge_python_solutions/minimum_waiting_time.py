from typing import List

from test_framework import generic_test


def minimum_total_waiting_time(service_times: List[int]) -> int:

    # Sort the service times in increasing order.
    service_times.sort()
    return sum(
        service_time * (len(service_times) - (i + 1))
        for i, service_time in enumerate(service_times)
    )


def minimum_total_waiting_time_pythonic(service_times):
    return sum(
        remaining_queries * time
        for remaining_queries, time in enumerate(sorted(service_times)[::-1]))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('minimum_waiting_time.py',
                                       'minimum_waiting_time.tsv',
                                       minimum_total_waiting_time))
