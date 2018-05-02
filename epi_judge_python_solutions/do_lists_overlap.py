import functools

from do_terminated_lists_overlap import overlapping_no_cycle_lists
from is_list_cyclic import has_cycle
from test_framework import generic_test
from test_framework.test_failure import TestFailure
from test_framework.test_utils import enable_executor_hook


def overlapping_lists(l0, l1):

    # Store the start of cycle if any.
    root0, root1 = has_cycle(l0), has_cycle(l1)

    if not root0 and not root1:
        # Both lists don't have cycles.
        return overlapping_no_cycle_lists(l0, l1)
    elif (root0 and not root1) or (not root0 and root1):
        # One list has cycle, one list has no cycle.
        return None
    # Both lists have cycles.
    temp = root1
    while True:
        temp = temp.next
        if temp is root0 or temp is root1:
            break

    # l0 and l1 do not end in the same cycle.
    if temp is not root0:
        return None  # Cycles are disjoint.

    # Calculates the distance between a and b.
    def distance(a, b):
        dis = 0
        while a is not b:
            a = a.next
            dis += 1
        return dis

    # l0 and l1 end in the same cycle, locate the overlapping node if they
    # first overlap before cycle starts.
    stem0_length, stem1_length = distance(l0, root0), distance(l1, root1)
    if stem0_length > stem1_length:
        l1, l0 = l0, l1
        root0, root1 = root1, root0
    for _ in range(abs(stem0_length - stem1_length)):
        l1 = l1.next
    while l0 is not l1 and l0 is not root0 and l1 is not root1:
        l0, l1 = l0.next, l1.next

    # If l0 == l1 before reaching root0, it means the overlap first occurs
    # before the cycle starts; otherwise, the first overlapping node is not
    # unique, we can return any node on the cycle.
    return l0 if l0 is l1 else root0


@enable_executor_hook
def overlapping_lists_wrapper(executor, l0, l1, common, cycle0, cycle1):
    if common:
        if not l0:
            l0 = common
        else:
            it = l0
            while it.next:
                it = it.next
            it.next = common

        if not l1:
            l1 = common
        else:
            it = l1
            while it.next:
                it = it.next
            it.next = common

    if cycle0 != -1 and l0:
        last = l0
        while last.next:
            last = last.next
        it = l0
        for _ in range(cycle0):
            if not it:
                raise RuntimeError('Invalid input data')
            it = it.next
        last.next = it

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

    common_nodes = set()
    it = common
    while it and id(it) not in common_nodes:
        common_nodes.add(id(it))
        it = it.next

    result = executor.run(functools.partial(overlapping_lists, l0, l1))

    if not (id(result) in common_nodes or (not common_nodes and not result)):
        raise TestFailure('Invalid result')


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main("do_lists_overlap.py",
                                       'do_lists_overlap.tsv',
                                       overlapping_lists_wrapper))
