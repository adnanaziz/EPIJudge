from test_framework.test_utils import enable_timer_hook
from test_framework.test_failure_exception import TestFailureException


def overlapping_no_cycle_lists(L1, L2):
    # Implement this placeholder.
    return None


@enable_timer_hook
def overlapping_no_cycle_lists_wrapper(timer, p1, p2, common):
    if common:
        if p1:
            l = p1
            while l.next:
                l = l.next
            l.next = common
        else:
            p1 = common

        if p2:
            l = p2
            while l.next:
                l = l.next
            l.next = common
        else:
            p2 = common

    timer.start()
    result = overlapping_no_cycle_lists(p1, p2)
    timer.stop()

    if result != common:
        raise TestFailureException('Invalid result')


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main(
        'do_terminated_lists_overlap.tsv', overlapping_no_cycle_lists_wrapper)
