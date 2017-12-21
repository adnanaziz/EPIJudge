from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook

RED, WHITE, BLUE = range(3)


def dutch_flag_partition(pivot_index, A):
    # Implement this placeholder.
    return


@enable_timer_hook
def dutch_flag_partition_wrapper(timer, data, pivot_idx):
    count = [0, 0, 0]
    for x in data:
        count[x] += 1
    pivot = data[pivot_idx]

    timer.start()
    dutch_flag_partition(pivot_idx, data)
    timer.stop()

    i = 0
    while i < len(data) and data[i] < pivot:
        count[data[i]] -= 1
        i += 1
    while i < len(data) and data[i] == pivot:
        count[data[i]] -= 1
        i += 1
    while i < len(data) and data[i] > pivot:
        count[data[i]] -= 1
        i += 1

    if i != len(data) or any(count):
        raise TestFailureException("Invalid output")


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('dutch_national_flag.tsv',
                                              dutch_flag_partition_wrapper)
