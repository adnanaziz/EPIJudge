from test_framework.test_failure_exception import TestFailureException
from test_framework.test_utils import enable_timer_hook


def has_cycle(head):
    # Implement this placeholder.
    return None


@enable_timer_hook
def has_cycle_wrapper(timer, head, cycle_idx):
    cycle_length = 0
    if cycle_idx != -1:
        if head is None:
            raise RuntimeError("Can't cycle empty list")
        cycle_start = None
        cursor = head
        while cursor.next is not None:
            if cursor.data == cycle_idx:
                cycle_start = cursor
            cursor = cursor.next
            cycle_length += 1 if cycle_start is not None else 0

        if cursor.data == cycle_idx:
            cycle_start = cursor
        if cycle_start is None:
            raise RuntimeError("Can't find a cycle start")
        cursor.next = cycle_start
        cycle_length += 1

    timer.start()
    result = has_cycle(head)
    timer.stop()

    if cycle_idx == -1:
        if result is not None:
            raise TestFailureException("Found a non-existing cycle")
    else:
        if result is None:
            raise TestFailureException("Existing cycle was not found")
        cursor = result
        while True:
            cursor = cursor.next
            cycle_length -= 1
            if cursor is None or cycle_length < 0:
                raise TestFailureException(
                    "Returned node does not belong to the cycle or is not the closest node to the head"
                )
            if cursor is result:
                break

    if cycle_length != 0:
        raise TestFailureException(
            "Returned node does not belong to the cycle or is not the closest node to the head"
        )


from test_framework import test_utils_generic_main, test_utils

if __name__ == '__main__':
    test_utils_generic_main.generic_test_main('is_list_cyclic.tsv',
                                              has_cycle_wrapper)
