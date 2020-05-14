from typing import Optional

from list_node import ListNode
from sorted_lists_merge import merge_two_sorted_lists
from test_framework import generic_test


def stable_sort_list(L: ListNode) -> Optional[ListNode]:

    # Base cases: L is empty or a single node, nothing to do.
    if L is None or L.next is None:
        return L

    # Find the midpoint of L using a slow and a fast pointer.
    pre_slow, slow, fast = None, L, L
    while fast and fast.next:
        pre_slow = slow
        fast, slow = fast.next.next, slow.next

    if pre_slow:
        pre_slow.next = None  # Splits the list into two equal-sized lists.
    return merge_two_sorted_lists(stable_sort_list(L), stable_sort_list(slow))


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('sort_list.py', 'sort_list.tsv',
                                       stable_sort_list))
