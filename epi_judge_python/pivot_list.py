from list_node import ListNode
from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook


def list_pivoting(l, x):
    # Implement this placeholder.
    return None


def linked_to_list(l):
    v = list()
    while l is not None:
        v.append(l.data)
        l = l.next
    return v


@enable_timer_hook
def list_pivoting_wrapper(timer, l, x):
    original = linked_to_list(l)

    timer.start()
    l = list_pivoting(l, x)
    timer.stop()

    pivoted = linked_to_list(l)
    mode = -1
    for i in pivoted:
        if mode == -1:
            if i == x:
                mode = 0
            elif i > x:
                mode = 1
        elif mode == 0:
            if i < x:
                raise TestFailureException('List is not pivoted')
            elif i > x:
                mode = 1
        else:
            if i <= x:
                raise TestFailureException('List is not pivoted')

    if sorted(original) != sorted(pivoted):
        raise TestFailureException('Result list contains different values')


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('pivot_list.tsv',
                                              list_pivoting_wrapper)
