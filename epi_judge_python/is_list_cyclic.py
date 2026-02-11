import functools
from typing import Optional

from list_node import ListNode
from test_framework import generic_test
from test_framework.test_failure import TestFailure
from test_framework.test_utils import enable_executor_hook


def has_cycle(head: ListNode) -> Optional[ListNode]:
    """Return None if there is no cycle, or the node at the start
    of the cycle if there is a cycle."""
    
    # If list has only 1 element, no cycle.
    if not head:
        return None
    if not head.next:
        return None
    
    # Slow and fast node.
    slow, fast = head, head
    i = 0
    while fast.next and fast.next.next:
        # Move fast up every round.
        fast = fast.next
        # Move slow up every other round.
        if i % 2:
            slow = slow.next
        
        # Detect cycle
        if fast is slow or fast.next is slow:
            # We have a cycle!
            # We can count the length of the cycle in O(n) time by
            # freezing slow and moving fast until it hits slow again.
            fast = slow.next
            cycle_length = 1
            while fast is not slow:
                fast = fast.next
                cycle_length += 1
            print(cycle_length)
            
            # Now that we have cycle length, we just start fast and slow at head.
            # increment slow after incrementing fast cycle_length times. once 
            # fast is slow, slow is the start of the cycle.
            fast, slow = head, head
            for _ in range(cycle_length):
                fast = fast.next
                
            while fast is not slow:
                fast = fast.next
                slow = slow.next
            
            return slow
        
        i += 1
    
    # If we reach the end (fast.next is None).
    return None


@enable_executor_hook
def has_cycle_wrapper(executor, head, cycle_idx):
    cycle_length = 0
    if cycle_idx != -1:
        if head is None:
            raise RuntimeError('Can\'t cycle empty list')
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
            raise RuntimeError('Can\'t find a cycle start')
        cursor.next = cycle_start
        cycle_length += 1

    result = executor.run(functools.partial(has_cycle, head))

    if cycle_idx == -1:
        if result is not None:
            raise TestFailure('Found a non-existing cycle')
    else:
        if result is None:
            raise TestFailure('Existing cycle was not found')
        cursor = result
        if result.data != cycle_idx:
            raise TestFailure(
                f"Returned node {result.data} is not the start of the cycle {cycle_idx}"
            )
        while True:
            cursor = cursor.next
            cycle_length -= 1
            if cursor is None or cycle_length < 0:
                raise TestFailure(
                    'Returned node does not belong to the cycle or is not the closest node to the head'
                )
            if cursor is result:
                break

    if cycle_length != 0:
        raise TestFailure(
            'Returned node does not belong to the cycle or is not the closest node to the head'
        )


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('is_list_cyclic.py',
                                       'is_list_cyclic.tsv',
                                       has_cycle_wrapper))
