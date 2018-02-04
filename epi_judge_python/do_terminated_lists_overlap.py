from test_framework.test_utils import enable_timer_hook
from test_framework.test_failure_exception import TestFailureException


def overlapping_no_cycle_lists(l0, l1):
    # Implement this placeholder.
    return None


@enable_timer_hook
def overlapping_no_cycle_lists_wrapper(timer, l0, l1, common):
    if common:
        if l0:
            i = l0
            while i.next:
                i = i.next
            i.next = common
        else:
            l0 = common

        if l1:
            i = l1
            while i.next:
                i = i.next
            i.next = common
        else:
            l1 = common

    timer.start()
    result = overlapping_no_cycle_lists(l0, l1)
    timer.stop()

    if result != common:
        raise TestFailureException('Invalid result')


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main('do_terminated_lists_overlap.tsv',
                                   overlapping_no_cycle_lists_wrapper)
