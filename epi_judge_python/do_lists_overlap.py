from is_list_cyclic import has_cycle
from do_terminated_lists_overlap import overlapping_no_cycle_lists
from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook


def overlapping_lists(L1, L2):
    # Implement this placeholder.
    return None


@enable_timer_hook
def overlapping_lists_wrapper(timer, l1, l2, common, cycle1, cycle2):
    if common:
        if not l1:
            l1 = common
        else:
            it = l1
            while it.next:
                it = it.next
            it.next = common

        if not l2:
            l2 = common
        else:
            it = l2
            while it.next:
                it = it.next
            it.next = common

    if cycle1 != -1 and l1:
        last = l1
        while last.next:
            last = last.next
        it = l1
        for _ in range(cycle1):
            if not it:
                raise RuntimeError('Invalid input data')
            it = it.next
        last.next = it

    if cycle2 != -1 and l2:
        last = l2
        while last.next:
            last = last.next
        it = l2
        for _ in range(cycle2):
            if not it:
                raise RuntimeError('Invalid input data')
            it = it.next
        last.next = it

    common_nodes = set()
    it = common
    while it and id(it) not in common_nodes:
        common_nodes.add(id(it))
        it = it.next

    timer.start()
    result = overlapping_lists(l1, l2)
    timer.stop()

    if not (id(result) in common_nodes or (not common_nodes and not result)):
        raise TestFailureException('Invalid result')


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('do_lists_overlap.tsv',
                                              overlapping_lists_wrapper)
