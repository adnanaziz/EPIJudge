from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook


def search_entry_equal_to_its_index(A):
    # Implement this placeholder.
    return 0


@enable_timer_hook
def search_entry_equal_to_its_index_wrapper(timer, A):
    timer.start()
    result = search_entry_equal_to_its_index(A)
    timer.stop()
    if result != -1:
        if A[result] != result:
            raise TestFailureException("Entry does not equal to its index")
    else:
        if any(i == a for i, a in enumerate(A)):
            raise TestFailureException(
                "There are entries which equal to its index")


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('search_entry_equal_to_index.tsv',
                                   search_entry_equal_to_its_index_wrapper)
