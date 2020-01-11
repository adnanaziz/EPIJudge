from typing import Optional

from list_node import ListNode
from reverse_list import reverse_list
from test_framework import generic_test


def zipping_linked_list(L: ListNode) -> Optional[ListNode]:

    if L is None or L.next is None:
        return L

    # Finds the second half of L.
    slow = fast = L
    while fast and fast.next:
        slow, fast = slow.next, fast.next.next

    first_half_head = L
    second_half_head = slow.next
    slow.next = None  # Splits the list into two lists.

    second_half_head = reverse_list(second_half_head)

    # Interleave the first half and the reversed of the second half.
    first_half_iter, second_half_iter = first_half_head, second_half_head
    while second_half_iter:
        second_half_iter.next, first_half_iter.next, second_half_iter = (
            first_half_iter.next, second_half_iter, second_half_iter.next)
        first_half_iter = first_half_iter.next.next
    return first_half_head


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('zip_list.py', 'zip_list.tsv',
                                       zipping_linked_list))
