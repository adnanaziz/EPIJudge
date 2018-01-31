from test_framework.test_utils import enable_timer_hook
from test_framework.test_failure_exception import TestFailureException

Subarray = collections.namedtuple('Subarray', ('start', 'end'))


def find_smallest_subarray_covering_set(paragraph, keywords):
    # Implement this placeholder.
    return Subarray(0, 0)


@enable_timer_hook
def find_smallest_subarray_covering_set_wrapper(timer, paragraph, keywords):
    copy = keywords

    timer.start()
    (start, end) = find_smallest_subarray_covering_set(paragraph, keywords)
    timer.stop()

    if start < 0 or start >= len(paragraph) or \
                    end < 0 or end >= len(paragraph) or \
                    start > end:
        raise TestFailureException("Index out of range")

    for i in range(start, end + 1):
        copy.discard(paragraph[i])

    if copy:
        raise TestFailureException("Not all keywords are in the range")

    return end - start + 1


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main(
        "smallest_subarray_covering_set.tsv",
        find_smallest_subarray_covering_set_wrapper)
